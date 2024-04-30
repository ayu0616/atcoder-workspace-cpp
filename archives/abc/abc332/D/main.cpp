#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll H, W;


int main() {
    cout << fixed << setprecision(18);
    cin >> H >> W;
    vvl A(H, vl(W)), B(H, vl(W));
    cin >> A >> B;
    map<vvl, int> dist;
    queue<pair<vvl, int>> q;
    q.push({A, 0});
    dist[A] = 0;
    while (!q.empty()) {
        auto [a, d] = q.front();
        q.pop();
        if (a == B) {
            cout << d << endl;
            return 0;
        }
        rep(i, H - 1) {
            auto tmp = a;
            swap(tmp[i], tmp[i + 1]);
            if (!dist.count(tmp)) {
                dist[tmp] = d + 1;
                q.push({tmp, d + 1});
            }
        }
        rep(i, W - 1) {
            auto tmp = a;
            rep(j, H) {
                swap(tmp[j][i], tmp[j][i + 1]);
            }
            if (!dist.count(tmp)) {
                dist[tmp] = d + 1;
                q.push({tmp, d + 1});
            }
        }
    }
    cout << -1 << endl;
}
