#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 15;

int n;
double d[N][N];
double ans[N], dist[N], delta[N];

void calc()
{
    double avg = 0;
    for (int i = 0; i < n + 1; i ++ )
    {
        dist[i] = delta[i] = 0;
        for (int j = 0; j < n; j ++ )
            dist[i] += (d[i][j] - ans[j]) * (d[i][j] - ans[j]);
        dist[i] = sqrt(dist[i]);
        avg += dist[i] / (n + 1);
    }
    for (int i = 0; i < n + 1; i ++ )
        for (int j = 0; j < n; j ++ )
            delta[j] += (dist[i] - avg) * (d[i][j] - ans[j]) / avg;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n + 1; i ++ )
        for (int j = 0; j < n; j ++ )
        {
            scanf("%lf", &d[i][j]);
            ans[j] += d[i][j] / (n + 1);
        }

    for (double t = 1e4; t > 1e-6; t *= 0.99995)
    {
        calc();
        for (int i = 0; i < n; i ++ )
            ans[i] += delta[i] * t;
    }
    for (int i = 0; i < n; i ++ ) printf("%.3lf ", abs(ans[i]));

    return 0;
}