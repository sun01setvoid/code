#include <iostream>
#include <map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    map<string, int> mp;
    string a[10] = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
    string b[12] = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
    int j = 0, k = 0;
    for (int i = 1984; i <= 2043; i++)
    {
        mp[a[j] + b[k]] = i;
        j = (j + 1) % 10;
        k = (k + 1) % 12;
    }
    string tmp;
    while (t--)
    {
        cin >> tmp;
        cout << mp[tmp] << endl;
    }
}