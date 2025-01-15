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
    Graph g(N + 1);
    vb visited(N + 1, false);
    visited[1] = true;
    auto dfs = [&](auto &&f, int cur) {
        string S;
        cin >> S;
        if (S == "OK" || S == "-1") {
            return true;
        }
        int k = stoi(S);
        vi v(k);
        cin >> v;
        for (auto &&i : v) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            cout << i << endl;
            if (f(f, i)) {
                return true;
            }
            cout << cur << endl;
            int k2;
            cin >> k2;
            vi v2(k2);
            cin >> v2;
        }
        return false;
    };
    dfs(dfs, 1);
}
