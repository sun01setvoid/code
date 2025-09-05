#include <bits/stdc++.h>
//__int128没有0,编译器版本太老
std::ostream& operator<<(std::ostream& os, __int128 x) {
    if (x == 0) return os << "0";
    if (x < 0) {
        os << '-';
        x = -x;
    }
    std::string s;
    while (x > 0) {
        s += '0' + x % 10;
        x /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}
std::istream& operator>>(std::istream& is, __int128& x) {
    std::string s;
    is >> s;
    x = 0;
    bool neg = false;
    size_t i = 0;
    
    if (s[0] == '-') {
        neg = true;
        i++;
    }
    for (; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            is.setstate(std::ios::failbit); 
            return is;
        }
        x = x * 10 + (s[i] - '0');
    }
    
    if (neg) x = -x;
    return is;
}