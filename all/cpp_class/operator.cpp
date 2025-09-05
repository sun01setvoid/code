#include <iostream>
#include <string>
#include <assert.h>
using namespace std;
class Vector {
private:
    int x, y;

public:
    Vector(int x = 0, int y = 0) : x(x), y(y) {}

    // 成员函数形式重载 "+"
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y);
    }

    // 友元函数形式重载 "*"
    friend Vector operator*(const Vector& v, int scalar);

    // 重载 "<<" 运算符
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

Vector operator*(const Vector& v, int scalar) {
    return Vector(v.x * scalar, v.y * scalar);
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
};
class Date {
private:
    int year, month, day;
    bool isLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }
    int getDaysOfMonth(int y, int m) {
        if (m == 2) {
            return isLeapYear(y) ? 29 : 28;
        }
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        }
        return 31;
    }
    int daysFrom1970() {    //经过的，当天不算
        int days = 0;
        for (int y = 1970; y < year; y++) {
            days += isLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month; m++) {
            days += getDaysOfMonth(year, m);
        }
        days += day - 1;
        return days;
    }
    void dateFromDays(int totalDays) {
        int y = 1970;
        while (true) {
            int daysInYear = isLeapYear(y) ? 366 : 365;
            if (totalDays < daysInYear) break;
            totalDays -= daysInYear;
            y++;
        }
        year = y;
        int m = 1;
        while (true) {
            int daysInMonth = getDaysOfMonth(year, m);
            if (totalDays < daysInMonth) break;
            totalDays -= daysInMonth;
            m++;
        }
        month = m;
        day = totalDays + 1;
    }
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    Date operator+(int n) {
        int totalDays = daysFrom1970() + n;
        Date newDate(year, month, day);
        newDate.dateFromDays(totalDays);
        return newDate;
    }
    Date operator-(int n) {
        int totalDays = daysFrom1970() - n;
        Date newDate(year, month, day);
        newDate.dateFromDays(totalDays);
        return newDate;
    }
    string toText() {
        string ystr = to_string(year);
        string mstr = to_string(month);
        string dstr = to_string(day);
        return ystr + "-" + mstr + "-" + dstr;
    }
};

int main()
{
    int y, m, d;
    cin >> y >> m >> d;
    Date d1(y,m,d);

    int n;
    cin >> n;

    cout << d1.toText() << " + " << n << " = " << (d1 + n).toText() << endl;
    cout << d1.toText() << " - " << n << " = " << (d1 - n).toText() << endl;
    return 0;
}