#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

map<string, bool> kaibun_memo;
bool is_kaibun(const string &s) {
    if (kaibun_memo.count(s)) {
        return kaibun_memo[s];
    }
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return kaibun_memo[s] = false;
        }
    }
    return kaibun_memo[s] = true;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    string S;
    cin >> N >> K >> S;

    map<string, mint> dp, prev;
    dp[string(K - 1, 'C')] = 1;
    for (char &c : S) {
        prev = dp;
        dp.clear();
        for (auto &p : prev) {
            string s = p.first;
            if (c == '?') {
                string t = s + 'A';
                if (!is_kaibun(t)) {
                    dp[t.substr(1)] += p.second;
                }
                t = s + 'B';
                if (!is_kaibun(t)) {
                    dp[t.substr(1)] += p.second;
                }
            } else {
                string t = s + c;
                if (!is_kaibun(t)) {
                    dp[t.substr(1)] += p.second;
                }
            }
        }
    }
    mint ans = 0;
    for (auto &p : dp) {
        ans += p.second;
    }
    cout << ans.val() << endl;
}
