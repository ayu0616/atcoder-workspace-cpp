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
    ll N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    cin >> S >> T;
    ll s_length = 0;
    for (auto &s : S) {
        s_length += s.size();
    }
    set<string> T_set;
    for (auto &t : T) {
        T_set.insert(t);
    }
    ll remain = 16 - s_length - (N - 1);
    vi indexes(N);
    iota(all(indexes), 0);

    auto solve = [&](auto &&self, string X, int i, int remain, vi &indexes) -> void {
        X += S[indexes[i]];
        if (i == N - 1) {
            if (!T_set.count(X)) {
                if (3 <= X.size() && X.size() <= 16) {
                    cout << X << endl;
                    exit(0);
                }
            }
            return;
        }
        if (remain < 0) return;
        if (X.size() >= 16) {
            return;
        }
        X += '_';
        self(self, X, i + 1, remain, indexes);
        while (remain--) {
            X += '_';
            self(self, X, i + 1, remain, indexes);
        }
    };

    do {
        solve(solve, "", 0, remain, indexes);
    } while (next_permutation(all(indexes)));
    cout << -1 << endl;
}
