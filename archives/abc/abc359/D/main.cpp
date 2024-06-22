#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    string S;
    cin >> N >> K >> S;
    mint rev = 0;
    int q_cnt = 0;
    rep(i, N) {
        if (S[i] == '?') {
            q_cnt++;
        }
    }
    rep(i, N - K + 1) {
        mint cnt = 1;
        int local_q_cnt = 0;
        rep(j, K) {
            if (S[i + j] == '?') {
                local_q_cnt++;
            }
        }
        rep(j, (K + 1) / 2) {
            int idx = i + j;
            int pair_idx = i + K - 1 - j;
            if (S[idx] == '?') {
                if (S[pair_idx] == '?') {
                    cnt *= 2;
                } else {
                }
            } else {
                if (S[pair_idx] == '?') {
                } else {
                    if (S[pair_idx] != S[idx]) {
                        cnt = 0;
                        break;
                    }
                }
            }
        }
        rev += mint(2).pow(q_cnt - local_q_cnt) * cnt;
    }
    mint ans = mint(2).pow(q_cnt) - rev;
    debug(rev);
    cout << ans << endl;
}
