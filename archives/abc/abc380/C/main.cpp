#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    string S;
    cin >> N >> K >> S;
    K--;
    vpii ones;
    bool is_one = false;
    rep(i, N) {
        char s = S[i];
        if (s == '1') {
            if (!is_one) {
                ones.push_back({i, i});
                is_one = true;
            } else {
                ones.back().second = i;
            }
        } else {
            is_one = false;
        }
    }

    pii one_k = ones[K];
    pii one_k_1 = ones[K - 1];

    rep(i, one_k.first, one_k.second + 1) { S[i] = '0'; }
    int one_size = one_k.second - one_k.first + 1;
    rep(i, one_k_1.second + 1, one_k_1.second + 1 + one_size) { S[i] = '1'; }

    cout << S << endl;
}
