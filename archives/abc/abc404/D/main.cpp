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
    ll N, M;
    cin >> N >> M;
    vl C(N);
    cin >> C;
    vector<set<int>> A(M);
    rep(i, M) {
        int k;
        cin >> k;
        rep(j, k) {
            int a;
            cin >> a;
            a--;
            A[i].insert(a);
        }
    }
    vvi zoo_animal(N);
    rep(i, M) {
        for (auto a : A[i]) {
            zoo_animal[a].push_back(i);
        }
    }
    ll ans = LL_INF;
    rep(S, pow(3, N)) {
        ll T = S;
        vector<int> cnt(N);
        rep(i, N) {
            int t = T % 3;
            T /= 3;
            cnt[i] += t;
        }
        ll cost = 0;
        rep(i, N) { cost += cnt[i] * C[i]; }
        vi animal_count(M);
        rep(i, N) {
            for (auto a : zoo_animal[i]) {
                animal_count[a] += cnt[i];
            }
        }
        bool ok = true;
        rep(i, M) {
            if (animal_count[i] < 2) {
                ok = false;
                break;
            }
        }
        if (ok) {
            chmin(ans, cost);
        }
    }
    cout << ans << endl;
}
