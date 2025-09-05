#include <iostream>
#include <vector>
using namespace std;
int N, M, K;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> M >> K;
        vector<vector<int>> mp(N, vector<int>(M));
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> mp[i][j];
            }
        }
        const int INF = N + 1;
        vector<vector<int>> mi(M + 1, vector<int>(K + 1, INF)),pre(K + 1, vector<int>(M + 1, INF));

        for (int j = 0; j < M; ++j)
        {
            int col = j + 1;
            for (int i = 0; i < N; ++i)
            {
                int cur = mp[i][j];
                mi[col][cur] = min(mi[col][cur], i + 1);
            }
        }
        for (int c = 1; c <= K; ++c)
        {
            pre[c][0] = INF;
            for (int j = 1; j <= M; ++j)
            {
                pre[c][j] = min(pre[c][j - 1], mi[j][c]);
            }
        }

        int ans = 0;
        for (int j = 1; j <= M; ++j)
        {
            int ma = 0;
            bool f = true;
            for (int c = 1; c <= K; ++c)
            {
                if (pre[c][j] == INF)
                {
                    f = false;
                    break;
                }
                ma = max(ma, pre[c][j]);
            }
            if (!f)
                continue;
            ans += N - ma + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}