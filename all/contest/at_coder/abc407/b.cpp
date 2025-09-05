#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    cout << fixed << setprecision(10);
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (abs(i - j) < b && i + j < a)
                ans++;
        }
    }
    cout << (36.0 - ans) / 36.0;
}