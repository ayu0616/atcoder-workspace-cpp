#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

string fixedNum(string a) {
    if (a.size() == 1) return a;
    for (int i = 0; i < a.size(); i++)
        if ('1' <= a[i] && a[i] <= '9') return a.substr(i, a.size());
    return "0";
}

string calcAddition(string a, string b) {
    a = fixedNum(a);
    b = fixedNum(b);
    int as = a.size(), bs = b.size(), d = as > bs ? as - bs : bs - as;
    string s = "0", t = "0";
    for (int i = 0; i < d; i++) as > bs ? t += "0" : s += "0";
    s += a;
    t += b;

    for (int i = s.size() - 1; i >= 1; i--) {
        s[i] += t[i] - '0';
        if (s[i] > '9') {
            s[i] -= 10;
            s[i - 1]++;
        }
    }

    return s[0] == '0' ? s.substr(1, s.size()) : s;
}

string calcMultiplication(string a, string b) {
    a = fixedNum(a);
    b = fixedNum(b);
    int as = a.size(), bs = b.size(), d = as > bs ? as - bs : bs - as;
    string s = "0", t = "0", x = "", sum = "", zero = "", digit = "";
    for (int i = 0; i < d; i++) as > bs ? t += "0" : s += "0";
    s += a;
    t += b;

    for (int i = 0; i < s.size(); i++) zero += "0";

    x = zero;
    sum = zero;

    for (int i = s.size() - 1; i >= 1; i--) {
        for (int j = s.size() - 1; j >= 1; j--) x[j] = (t[i] - '0') * (s[j] - '0');
        for (int j = s.size() - 1; j >= 1; j--) {
            int f = x[j] / 10;
            x[j - 1] += f;
            x[j] = x[j] - 10 * f + '0';
        }
        x += digit;
        sum = calcAddition(x, sum);
        digit += "0";
        x = zero;
    }
    return sum;
}
int main() {
    int N;
    cin >> N;
    vs A(N);
    cin >> A;
    map<string, int> mp;
    rep(i, N) { mp[A[i]]++; }

    ll ans = 0;
    rep(i, N) {
        string ai = A[i];
        rep(j, N) {
            string aj = A[j];
            string aij = calcMultiplication(ai, aj);
            ans += mp[aij];
        }
    }
    cout << ans << endl;
}
