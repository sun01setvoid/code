#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>
using namespace std;
const int N = 1e7 + 10, BASE = 10; // BASE是进制

int q[N], tmp[N], backup[N];
int help[N], cnt[N];

clock_t t;

void fisherYatesShuffle(int q[], int n) {
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(q[i],q[j]);
    }
}

bool checktime()
{
    if (clock() - t > 5*60*1000 )
        return true;
    return false;
}
bool check(int q[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (q[i] > q[i + 1])
        {
            return false;
        }
    }
    return true;
}

void mrs(int q[], int l, int r)
{
    if (checktime())
    {
        cout << "time_limit_exceeded";
        exit(0);
    }
    if (l == r)
        return;
    int m = (l + r) >> 1;
    mrs(q, l, m);
    mrs(q, m + 1, r);
    int k = 0, i = l, j = m + 1;
    while (i <= m && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while (i <= m)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

void qs(int q[], int l, int r)
{
    if (checktime())
    {
        cout << "time_limit_exceeded";
        exit(0);
    }
    if (l >= r)
        return;
    int x = q[l + r >> 1], i = l - 1, j = r + 1; // 一般选中间，防止一开始直接有序的情况
    while (i < j)
    {
        while (q[++i] < x)
            ;
        while (q[--j] > x)
            ;
        if (i < j)
            swap(q[i], q[j]);
    }
    qs(q, l, j);
    qs(q, j + 1, r);
}

void bubble_sort(int q[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (checktime())
        {
        cout << "time_limit_exceeded";
        exit(0);
        }
        for (int j = 0; j < n - 1; j++)
        {
            if (q[j] > q[j + 1])
            {
                swap(q[j], q[j + 1]);
            }
        }
    }
}

void choice_sort(int q[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (checktime())
        {
        cout << "time_limit_exceeded";
        exit(0);
        }
        int k = i;
        for (int j = i; j < n; j++)
        {
            if (q[j] < q[k])
                k = j;
        }
        if (k != i)
        {
            swap(q[i], q[k]);
        }
    }
}

void insert_sort(int q[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (checktime())
        {
        cout << "time_limit_exceeded";
        exit(0);
        }
        int j;
        int num = q[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (q[j] > num)
            {
                q[j + 1] = q[j];
            }
            else
                break;
        }
        q[j + 1] = num;
    }
}

void base_sort(int q[], int n, int bits)
{ // bits是数字在BASE进制下的位数

    for (int offset = 1; bits > 0; offset *= BASE, bits--)
    {
        if (checktime())
        {
        cout << "time_limit_exceeded";
        exit(0);
        }
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++)
            cnt[q[i] / offset % BASE]++;
        for (int i = 1; i < BASE; i++)
            cnt[i] += cnt[i - 1]; // 前缀和
        for (int i = n - 1; i >= 0; i--)
            help[cnt[q[i] / offset % BASE]--] = q[i];
        for (int i = 0; i < n; i++)
            q[i] = help[i];
    }
}

int main()
{
    srand((unsigned int)time(0));
    int n,m;
    cout<<"数组长度为n和数据范围为(0~10^m-1),输入n和m\n";
    cin >> n >> m;
    // 生成数组
    int dig=1;
    for (int i=1;i<=m;i++){
        dig*=10;
    }
    for (int i = 0; i < n; i++)
    {
        backup[i] = rand() % dig;
        //cout << backup[i] << " ";
    }
    //cout << "\n";

    // 冒泡排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    bubble_sort(q, n);
    cout << "bubble_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 选择排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    choice_sort(q, n);
    cout << "choice_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 插入排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    insert_sort(q, n);
    cout << "insert_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 归并排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    mrs(q, 0, n - 1);
    cout << "merge_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 快速排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    qs(q, 0, n - 1);
    cout << "quick_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 基数排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    base_sort(q, n, m);
    cout << "base_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    //打乱
    fisherYatesShuffle(backup, n);
    cout<<"Shuffle 后:\n\n";
    //冒泡
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    bubble_sort(q, n);
    cout << "bubble_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 选择排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    choice_sort(q, n);
    cout << "choice_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 插入排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    insert_sort(q, n);
    cout << "insert_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 归并排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    mrs(q, 0, n - 1);
    cout << "merge_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 快速排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    qs(q, 0, n - 1);
    cout << "quick_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

    // 基数排序
    for (int i = 0; i < n; i++)
    {
        q[i] = backup[i];
    }
    t = clock();
    base_sort(q, n, m);
    cout << "base_sort:";
    if (check(q, n))
        cout << "true" << "\n";
    else
        cout << "flase\n";
    cout << "Time used:" << clock() - t << "ms\n\n";

}