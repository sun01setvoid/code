#include <bits/stdc++.h>
using namespace std;
vector<int> div(const vector<int> &A, int b, int &r)
{
    vector<int> C;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
vector<int> shiftLeft(const vector<int> &a, int shift)
{
    vector<int> result(a);
    result.insert(result.begin(), shift, 0);
    return result;
}

vector<int> mul(const vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; ++i)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

vector<int> add(const vector<int> &A, const vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size() || t; ++i)
    {
        if (i < A.size())
            t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}

vector<int> sub(const vector<int> &A, const vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        t = t < 0 ? 1 : 0;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b)
{
    if (a.size() <= 8)
    {
        int tmp = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            tmp = tmp * 10 + a[i];
        return mul(b, tmp);
    }
    if (b.size() <= 8)
    {
        int tmp = 0;
        for (int i = b.size() - 1; i >= 0; --i)
            tmp = tmp * 10 + b[i];
        return mul(a, tmp);
    }

    int n = max(a.size(), b.size());
    // 填充到n位以确保分解正确
    // 不写就错？？？？
    vector<int> a_padded(a), b_padded(b);
    a_padded.resize(n, 0);
    b_padded.resize(n, 0);

    int half = (n + 1) / 2;

    vector<int> a_low(a_padded.begin(), a_padded.begin() + half);
    vector<int> a_high(a_padded.begin() + half, a_padded.end());
    vector<int> b_low(b_padded.begin(), b_padded.begin() + half);
    vector<int> b_high(b_padded.begin() + half, b_padded.end());

    vector<int> z0 = karatsuba(a_low, b_low);
    vector<int> z2 = karatsuba(a_high, b_high);

    vector<int> a_sum = add(a_low, a_high);
    vector<int> b_sum = add(b_low, b_high);
    vector<int> z1 = karatsuba(a_sum, b_sum);

    vector<int> z1_z0 = sub(z1, z0);
    vector<int> z1_z0_z2 = sub(z1_z0, z2);

    vector<int> result = add(add(shiftLeft(z2, 2 * half), shiftLeft(z1_z0_z2, half)), z0);
    return result;
}

int main()
{
    string a, b;
    cin >> a >> b;
    vector<int> A, B;
    for (int i = a.size() - 1; i >= 0; --i)
        A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; --i)
        B.push_back(b[i] - '0');
    vector<int> result = karatsuba(A, B);
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();
    for (int i = result.size() - 1; i >= 0; --i)
        cout << result[i];
    return 0;
}