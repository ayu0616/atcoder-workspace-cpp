#include <bit>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    string S;
    ll Q;
    cin >> S >> Q;
    vl K(Q);
    cin >> K;
    ll N = S.size();
    vector<char> ans;
    for (ll k : K) {
        k--;
        ll i = k / N;
        ll j = k % N;
        int i_pc = popcount((unsigned long long)i);
        bool is_reverse = i_pc % 2 == 1;
        if (is_reverse) {
            if ('A' <= S[j] && S[j] <= 'Z') {
                ans.push_back((char)(S[j] + 32));
            } else {
                ans.push_back((char)(S[j] - 32));
            }
        } else {
            ans.push_back(S[j]);
        }
    }
    cout << ans << endl;
}
