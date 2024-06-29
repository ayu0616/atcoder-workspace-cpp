#include <functional>
#include <string>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;
using mint = static_modint<MOD>;

constexpr int B1 = 1 << 30;
constexpr int B2 = 998244353;
constexpr int B3 = (1 << 30) - 952621;

using mint1 = static_modint<B1>;
using mint2 = static_modint<B2>;
using mint3 = static_modint<B3>;

using hash_t = tuple<ll, ll, ll>;
using mp = map<hash_t, mint>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    string S;
    cin >> N >> S;
    // vi int_s(N);
    // for (int i = 0; i < N; i++) {
    //     int_s[i] = S[i] - 'A';
    // }
    // int h1 = 0, h2 = 0, h3 = 0;
    // for (int i = 0; i < N; i++) {
    //     h1 += (mint1(2).pow(i) * int_s[i]).val();
    //     h2 += (mint2(2).pow(i) * int_s[i]).val();
    //     h3 += (mint3(2).pow(i) * int_s[i]).val();
    // }
    // hash_t h = make_tuple(h1, h2, h3);
    map<string, mint> dp;
    dp[S] = 1;
    deque<string> q;
    q.push_back(S);
    mint ans = 0;
    while (!q.empty()) {
        string s = q.front();
        q.pop_front();
        int n = s.size();
        for (int i = 0; i < n - 2; i++) {
            if (s.substr(i, 3) == "ABA") {
                string t = "";
                t += s.substr(0, i);
                t += "A";
                t += s.substr(i + 3);
                q.push_back(t);
                dp[t] += dp[s];
            } else if (s.substr(i, 3) == "BAB") {
                string t = "";
                t += s.substr(0, i);
                t += "B";
                t += s.substr(i + 3);
                q.push_back(t);
                dp[t] += dp[s];
            } else {
                ans += dp[s];
            }
        }
    }
    cout << ans << endl;
}