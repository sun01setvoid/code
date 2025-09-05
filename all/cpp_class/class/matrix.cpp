#include <iostream>
#include <iomanip>
using namespace std;
class matrix
{
private:
    int row;
    int column;
    int **mat;

public:
    matrix(int a = 0, int b = 0) : row(a), column(b) {};
    void get(int, int);
    void display();
    friend bool judge(const matrix &a, const matrix &b);
    friend matrix operator*(const matrix &a, const matrix &b);
};
void matrix::get(int a, int b)
{
    int v, q;
    row = a;
    column = b;
    mat = new int *[a];
    for (v = 0; v < a; v++)
    {
        mat[v] = new int[b];
    }
    for (v = 0; v < row; v++)
    {
        for (q = 0; q < column; q++)
        {
            cin >> mat[v][q];
        }
    }
}
bool judge(const matrix &a, const matrix &b)
{
    if (a.column == b.row || a.column == 1 && a.row == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void matrix::display()
{
    int v, q;
    for (v = 0; v < row; v++)
    {
        for (q = 0; q < column; q++)
        {
            cout << setw(10) << mat[v][q];
        }
        cout << endl;
    }
}
matrix operator*(const matrix &a, const matrix &b)
{
    matrix c;
    int v = 0, q = 0, k = 0, l = 0, sum = 0;
    if (a.column == 1 && a.row == 1)
    {
        c.row = b.row;
        c.column = b.column;
        c.mat = new int *[b.row];
        for (v = 0; v < b.row; v++)
        {
            c.mat[v] = new int[b.column];
        }
        for (v = 0; v < b.row; v++)
        {
            for (q = 0; q < b.column; q++)
            {
                c.mat[v][q] = a.mat[0][0] * b.mat[v][q];
            }
        }
    }
    else
    {
        c.row = a.row;
        c.column = b.column;
        c.mat = new int *[a.row];
        for (v = 0; v < a.row; v++)
        {
            c.mat[v] = new int[b.column];
        }
        for (v = 0; v < a.row; v++)
        {
            for (q = 0; q < b.column; q++)
            {
                for (k = 0; k < a.column; k++)
                {
                    sum += a.mat[v][k] * b.mat[k][q];
                }
                c.mat[v][q] = sum;
                sum = 0;
            }
        }
    }
    return c;
}
int main()
{
    matrix m1, m2, m3;
    int a, b;
    cin >> a >> b;
    m1.get(a, b);
    cin >> a >> b;
    m2.get(a, b);
    if (judge(m1, m2))
    {
        m3 = m1 * m2;
        m3.display();
    }
    else
    {
        cout << "Invalid Matrix multiplication!" << endl;
    }
    return 0;
}
