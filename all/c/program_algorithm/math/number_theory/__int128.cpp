/*
struct i128 {
    using u64 = uint64_t;
    using i64 = int64_t;

    u64 lo;
    i64 hi;

    i128(i64 v = 0) : lo((u64)v), hi(v < 0 ? -1 : 0) {}

    static i128 from_parts(u64 low, i64 high) {
        i128 res;
        res.lo = low;
        res.hi = high;
        return res;
    }
    i128 operator+(const i128& rhs) const {
        i128 res;
        res.lo = lo + rhs.lo;
        res.hi = hi + rhs.hi + (res.lo < lo);
        return res;
    }
    i128 operator-(const i128& rhs) const {
        i128 res;
        res.lo = lo - rhs.lo;
        res.hi = hi - rhs.hi - (lo < rhs.lo);
        return res;
    }
    i128 operator-() const {
        return i128(0) - *this;
    }
    i128 operator*(const i128& rhs) const {
        u64 a = lo, b = rhs.lo;
        u64 a_lo = a & 0xffffffffULL, a_hi = a >> 32;
        u64 b_lo = b & 0xffffffffULL, b_hi = b >> 32;

        u64 lo_lo = a_lo * b_lo;
        u64 lo_hi = a_lo * b_hi + a_hi * b_lo;
        u64 hi_hi = a_hi * b_hi;

        u64 carry = (lo_lo >> 32) + (lo_hi & 0xffffffffULL);
        u64 low = (lo_lo & 0xffffffffULL) + (carry << 32);
        i64 high = hi * rhs.lo + rhs.hi * lo + hi_hi + (lo_hi >> 32) + (carry >> 32);

        return from_parts(low, high);
    }
    bool operator==(const i128& rhs) const {
        return hi == rhs.hi && lo == rhs.lo;
    }
    bool operator!=(const i128& rhs) const { return !(*this == rhs); }
    bool operator<(const i128& rhs) const {
        return hi < rhs.hi || (hi == rhs.hi && lo < rhs.lo);
    }
    bool operator>(const i128& rhs) const { return rhs < *this; }
    bool operator<=(const i128& rhs) const { return !(rhs < *this); }
    bool operator>=(const i128& rhs) const { return !(*this < rhs); }
    friend void divmod(i128 a, i128 b, i128& q, i128& r) {
        bool neg_a = a.hi < 0, neg_b = b.hi < 0;
        if (neg_a) a = -a;
        if (neg_b) b = -b;

        q = 0;
        r = 0;
        for (int i = 127; i >= 0; --i) {
            r = r << 1;
            r.lo |= (a >> i) & 1;
            if (r >= b) {
                r = r - b;
                q = q | (i128(1) << i);
            }
        }

        if (neg_a != neg_b) q = -q;
        if (neg_a) r = -r;
    }
    i128 operator/(const i128& rhs) const {
        i128 q, r;
        divmod(*this, rhs, q, r);
        return q;
    }
    i128 operator%(const i128& rhs) const {
        i128 q, r;
        divmod(*this, rhs, q, r);
        return r;
    }
    i128 operator<<(int n) const {
        n %= 128;
        if (n == 0) return *this;
        if (n < 64) {
            return from_parts(lo << n, (hi << n) | (i64)(lo >> (64 - n)));
        }
        else {
            return from_parts(0, (i64)(lo << (n - 64)));
        }
    }
    i128 operator>>(int n) const {
        n %= 128;
        if (n == 0) return *this;
        if (n < 64) {
            return from_parts((lo >> n) | ((u64)hi << (64 - n)), hi >> n);
        }
        else {
            return from_parts((u64)(hi >> (n - 64)), hi >= 0 ? 0 : -1);
        }
    }
    i128 operator|(const i128& rhs) const {
        return from_parts(lo | rhs.lo, hi | rhs.hi);
    }
    i128 operator&(const i128& rhs) const {
        return from_parts(lo & rhs.lo, hi & rhs.hi);
    }
    u64 operator&(u64 mask) const {
        return lo & mask;
    }
    std::string to_string() const {
        if (*this == i128(0)) return "0";
        i128 tmp = *this;
        bool neg = tmp.hi < 0;
        if (neg) tmp = -tmp;

        std::string res;
        while (tmp != i128(0)) {
            i128 q = tmp / 10;
            u64 rem = (tmp - q * 10).lo;
            res += char('0' + rem);
            tmp = q;
        }
        if (neg) res += '-';
        std::reverse(res.begin(), res.end());
        return res;
    }
    friend std::ostream& operator<<(std::ostream& os, const i128& val) {
        return os << val.to_string();
    }
    friend std::istream& operator>>(std::istream& is, i128& val) {
        std::string s;
        is >> s;
        val = 0;
        bool neg = false;
        size_t i = 0;
        if (s[0] == '-') neg = true, i = 1;
        for (; i < s.size(); ++i) val = val * 10 + (s[i] - '0');
        if (neg) val = -val;
        return is;
    }
};
*/
