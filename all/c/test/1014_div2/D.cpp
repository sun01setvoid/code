#include <iostream>
#include <vector>
using namespace std;
int cnt[3];
int main()
{
    int t, n;
    string s;
    cin >> t;
    while (t--)
    {
        vector<vector<int>> idx(3);
        cnt[0] = cnt[1] = cnt[2] = 0;
        cin >> n;
        int flag = 1;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (i < s.size() - 1 && s[i] != s[i + 1])
            {
                if (s[i] == 'L' && s[i + 1] == 'I' || s[i] == 'I' && s[i + 1] == 'L')
                    idx[2].push_back(i + 1);
                else if (s[i] == 'L' && s[i + 1] == 'T' || s[i] == 'T' && s[i + 1] == 'L')
                    idx[1].push_back(i + 1);
                else if (s[i] == 'I' && s[i + 1] == 'T' || s[i] == 'T' && s[i + 1] == 'I')
                    idx[0].push_back(i + 1);
                flag = 0;
            }
            if (s[i] == 'L')
                cnt[0]++;
            else if (s[i] == 'I')
                cnt[1]++;
            else
                cnt[2]++;
        }
        if (flag)
        {
            cout << "-1" << endl;
            continue;
        }
        int ma = max(cnt[0], max(cnt[1], cnt[2]));
        vector<int> ma_id, oth;
        for (int i = 0; i <= 2; i++)
        {
            if (cnt[i] == ma)
                ma_id.push_back(i);
            else
                oth.push_back(i);
        }
        if (ma_id.size() == 3)
            cout << 0 << endl;
        else if (ma_id.size() == 2)
        {
            int cur = oth[0];
            if (idx[cur].size() >= ma - cnt[cur])
            {
                cout << ma - cnt[cur] << endl;
                int st = 0;
                for (int i = 0; i < ma - cnt[cur]; i++)
                    cout << st + idx[cur][i] << endl, st++;
            }
            else
                cout << "-1" << endl;
        }
        else
        {
            int t1 = oth[0], t2 = oth[1];
            if (cnt[t1] == cnt[t2])
            {
                cout << 2 * (ma - cnt[t1]) << endl;
                int st = 0;
                if (idx[t1].size())
                {
                    while (st < 2 * (ma - cnt[t1]))
                    {
                        cout << st + idx[t1][0] << endl;
                        st++;
                        cout << st + idx[t1][0] << endl;
                        st++;
                    }
                }
                else if (idx[t2].size())
                {
                    while (st < 2 * (ma - cnt[t1]))
                    {
                        cout << st + idx[t2][0];
                        st++;
                        cout << st + idx[t2][0];
                        st++;
                    }
                }
            }
            else if (cnt[t1] < cnt[t2])
            {
                if (idx[t1].size() >= cnt[t2] - cnt[t1])
                {
                    cout << 2 * cnt[ma_id[0]] - cnt[t1] - cnt[t2] << endl;
                    int st = 0;
                    for (int i = 0; i < cnt[t2] - cnt[t1]; i++)
                    {
                        if (i == 0)
                        {
                            while (st < 2 * (cnt[ma_id[0]] - cnt[t2]))
                            {
                                cout << st + idx[t1][0] << endl;
                                st++;
                                cout << st + idx[t1][0] << endl;
                                st++;
                            }
                            cout << st + idx[t1][i] << endl, st++;
                        }
                        cout << st + idx[t1][i] << endl, st++;
                    }
                }
                else
                    cout << "-1" << endl;
            }
            else
            {
                if (idx[t2].size() >= cnt[t1] - cnt[t2])
                {
                    cout << 2 * cnt[ma_id[0]] - cnt[t1] - cnt[t2] << endl;
                    int st = 0;
                    for (int i = 0; i < cnt[t1] - cnt[t2]; i++)
                    {
                        if (i == 0)
                        {
                            while (st < 2 * (cnt[ma_id[0]] - cnt[t1]))
                            {
                                cout << st + idx[t2][0] << endl;
                                st++;
                                cout << st + idx[t2][0] << endl;
                                st++;
                            }
                            cout << st + idx[t2][i] << endl, st++;
                        }
                        cout << st + idx[t2][i] << endl, st++;
                    }
                }
                else
                    cout << "-1" << endl;
            }
        }
    }
}