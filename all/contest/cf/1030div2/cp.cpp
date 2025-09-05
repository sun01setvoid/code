#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const long long MAX_STRIP = 1000000000000000LL;

int mark[500][2][500] = {0};
int global_now = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> p(n);
        vector<long long> d(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }
        int q;
        cin >> q;
        vector<long long> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i];
        }

        for (long long a_i : queries) {
            global_now++;
            long long pos = a_i;
            long long tm_val = 0;
            int dir = 1;

            auto it_start = lower_bound(p.begin(), p.end(), pos);
            if (it_start != p.end() && *it_start == pos) {
                int idx = it_start - p.begin();
                if (tm_val == d[idx]) {
                    dir = -dir;
                }
            }

            pos = pos + dir;
            tm_val = (tm_val + 1) % k;

            if (pos < 1 || pos > MAX_STRIP) {
                cout << "YES\n";
                continue;
            }

            bool found_light = false;
            int next_light_index = -1;
            if (dir == 1) {
                auto it = upper_bound(p.begin(), p.end(), pos);
                if (it != p.end()) {
                    next_light_index = it - p.begin();
                    long long next_light_pos = p[next_light_index];
                    long long steps = next_light_pos - pos;
                    tm_val = (tm_val + steps) % k;
                    pos = next_light_pos;
                    found_light = true;
                } else {
                    cout << "YES\n";
                    continue;
                }
            } else {
                auto it = lower_bound(p.begin(), p.end(), pos);
                if (it == p.begin()) {
                    cout << "YES\n";
                    continue;
                } else {
                    --it;
                    next_light_index = it - p.begin();
                    long long next_light_pos = *it;
                    long long steps = pos - next_light_pos;
                    tm_val = (tm_val + steps) % k;
                    pos = next_light_pos;
                    found_light = true;
                }
            }

            if (!found_light) {
                cout << "YES\n";
                continue;
            }

            int current_light_index = next_light_index;
            int current_dir = dir;
            long long current_tm = tm_val;
            string ans = "";
            while (ans == "") {
                int dir_index = (current_dir == 1) ? 0 : 1;
                if (mark[current_light_index][dir_index][current_tm] == global_now) {
                    ans = "NO";
                    break;
                }
                mark[current_light_index][dir_index][current_tm] = global_now;

                int new_dir = current_dir;
                if (current_tm == d[current_light_index]) {
                    new_dir = -new_dir;
                }

                long long new_tm_val = (current_tm + 1) % k;
                long long new_pos = p[current_light_index] + new_dir;

                if (new_pos < 1 || new_pos > MAX_STRIP) {
                    ans = "YES";
                    break;
                }

                int next_light_index = -1;
                if (new_dir == 1) {
                    auto it_next = upper_bound(p.begin(), p.end(), new_pos);
                    if (it_next != p.end()) {
                        next_light_index = it_next - p.begin();
                        long long next_light_pos = p[next_light_index];
                        long long steps = next_light_pos - new_pos;
                        new_tm_val = (new_tm_val + steps) % k;
                    } else {
                        ans = "YES";
                        break;
                    }
                } else {
                    auto it_next = lower_bound(p.begin(), p.end(), new_pos);
                    if (it_next == p.begin()) {
                        ans = "YES";
                        break;
                    } else {
                        --it_next;
                        next_light_index = it_next - p.begin();
                        long long next_light_pos = *it_next;
                        long long steps = new_pos - next_light_pos;
                        new_tm_val = (new_tm_val + steps) % k;
                    }
                }

                current_light_index = next_light_index;
                current_dir = new_dir;
                current_tm = new_tm_val;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}