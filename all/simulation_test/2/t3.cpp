#include <bits/stdc++.h>
using namespace std;

// 正确代码
int correct_solution(int k, int l, int m)
{
    int a1 = 1, a2 = k / 2 + 1, b1 = 1, b2 = l / 2 + 1, c1 = 1, c2 = m / 2 + 1;
    int now = 0;
    int st = 1;
    while (now <= k * l * m)
    {
        int ad = 0;
        if (st == 1 || st == 2)
            ad = k / 2;
        else if (st == 3 || st == 4)
            ad = l / 2;
        else
            ad = m / 2;
        now += ad;
        a1 = (a1 + ad - 1) % k + 1;
        a2 = (a2 + ad - 1) % k + 1;
        b1 = (b1 - ad + l - 1 + l * 100) % l + 1;
        b2 = (b2 - ad + l - 1 + l * 100) % l + 1;
        c1 = (c1 + ad - 1) % m + 1;
        c2 = (c2 + ad - 1) % m + 1;
        if (st == 1)
        {
            if (a2 < b1)
                st = 3;
            else
                st = 2;
        }
        else if (st == 2)
            st = 1;
        else if (st == 3)
        {
            if (b2 < c1)
                st = 5;
            else
                st = 4;
        }
        else if (st == 4)
        {
            if (b1 < a2)
                st = 2;
            else
                st = 3;
        }
        else if (st == 5)
            break;
    }
    if (now <= k * l * m)
        return now;
    else
        return -1;
}

// 待测试的代码
int my_solution(int k, int l, int m)
{
    int step = 1;
    for (int i = 1; i <= 400; i++)
    {
        if (i & 1)
        {
            while ((k / 2 + k / 2 * step + l / 2 * (i - 1)) % k >= ((l - k / 2 * step - l / 2 * (i - 1)) % l + l) % l)
            {
                step += 2;
                if (step >= 400)
                {
                    return -1;
                }
            }
            int t2 = ((l / 2 - k / 2 * step - l / 2 * i) % l + l) % l;
            int t3 = (k / 2 * step + l / 2 * i) % m;
            if (t2 < t3)
            {
                return k / 2 * step + m / 2 + l / 2 * i;
            }
        }
        else
        {
            int t1 = (k / 2 + k / 2 * step + l / 2 * i) % k;
            int t2 = ((l - k / 2 * step - l / 2 * i) % l + l) % l;
            if (t1 > t2)
                step += 2;
        }
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 4; i <= 100; i += 2)
    {
        for (int j = 4; j <= 100; j += 2)
        {
            for (int k = 4; k <= 100; k += 2)
            {
                int ans1 = my_solution(i, j, k), ans2 = correct_solution(i, j, k);
                if (ans1 != ans2)
                {
                    cout << "mp[{" << i << "," << j << ", " << k << ",}]= " << ans2 << ";" << endl;
                }
            }
        }
    }
    return 0;
}