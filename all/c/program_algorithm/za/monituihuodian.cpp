#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>

#define x first
#define y second

using namespace std;

typedef pair<double, double> PDD;
const int N = 110;

int n;
PDD q[N];
double ans = 1e8;

double rand(double l, double r)
{
    return (double)rand() / RAND_MAX * (r - l) + l;
}

double get_dist(PDD a, PDD b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double calc(PDD p)
{
    double res = 0;
    for (int i = 0; i < n; i ++ )
        res += get_dist(p, q[i]);
    ans = min(ans, res);
    return res;
}

void simulate_anneal()
{
    PDD cur(rand(0, 10000), rand(0, 10000));
    for (double t = 1e4; t > 1e-4; t *= 0.9)
    {
        PDD np(rand(cur.x - t, cur.x + t), rand(cur.y - t, cur.y + t));
        double dt = calc(np) - calc(cur);
        if (exp(-dt / t) > rand(0, 1)) cur = np;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%lf%lf", &q[i].x, &q[i].y);

    for (int i = 0; i < 100; i ++ ) simulate_anneal();
    printf("%.0lf\n", ans);

    return 0;
}