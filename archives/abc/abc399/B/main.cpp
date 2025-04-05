#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl P(N);
    rep(i, N) cin >> P[i];
    vi rank(N, -1);
    int r = 1;
    while (find(all(rank), -1) != rank.end()) {
        int x = 0;
        vi idx;
        rep(i, N) {
            if (rank[i] == -1) {
                if (x < P[i]) {
                    x = P[i];
                    idx.clear();
                    idx.push_back(i);
                } else if (x == P[i]) {
                    idx.push_back(i);
                }
            }
        }
        for (auto i : idx) {
            rank[i] = r;
        }
        int k = idx.size();
        r += k;
    }
    rep(i, N) cout << rank[i] << endl;
}
