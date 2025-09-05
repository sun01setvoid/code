#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        int k = 0;
        while (x > 0)
        {
            x >>= 1;
            k++;
        }
        cout << 2 * k + 1 << '\n';
    }
    return 0;
}