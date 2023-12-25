#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char *d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

__int128_t parse(string &s) {
    __int128_t ret = 0;
    for (int i = 0; i < s.length(); i++)
        if ('0' <= s[i] && s[i] <= '9') ret = 10 * ret + s[i] - '0';
    if (s[0] == '-') ret *= -1;
    return ret;
}

string s = "1000000000000000000";
__int128_t one_e_18 = parse(s);

int main() {
    string sA, sM, sL, sR;
    cin >> sA >> sM >> sL >> sR;
    __int128_t A = parse(sA);
    __int128_t M = parse(sM);
    __int128_t L = parse(sL);
    __int128_t R = parse(sR);

    A += one_e_18;
    L += one_e_18;
    R += one_e_18;
    __int128_t kl = (L - A) / M;
    if ((L - A) % M != 0) kl++;
    __int128_t kr = (R - A) / M;
    cout << kr - kl + 1 << endl;
}
