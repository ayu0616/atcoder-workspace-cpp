#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;

    map<int, int> portion, enemy;
    vpii query(N);
    rep(i, N) {
        int t, x;
        cin >> t >> x;
        query[i] = {t, x};
        if (t == 1) {
            portion[x]++;
        } else {
            enemy[x]++;
            if (portion[x] < enemy[x]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    map<int, vi> used;
    map<int, vi> p_idx;
    rep(i, N) {
        auto [t, x] = query[i];
        if (t == 1) p_idx[x].push_back(i);
    }
    int k = 0, k_min = 0;
    vi ans(N, 0);
    for (int i = N - 1; i >= 0; i--) {
        auto [t, x] = query[i];
        if (t == 1) {
            continue;
        } else {
            auto it = lower_bound(all(p_idx[x]), i);
            if (it != p_idx[x].begin()) it--;
            ans[*it] = 1;
            p_idx[x].erase(it);
        }
    }
    vi a;
    rep(i, N) {
        auto [t, x] = query[i];
        if (t == 1) a.push_back(ans[i]);
    }
    rep(i, N) {
        auto [t, x] = query[i];
        if (t == 1) {
            if (ans[i] == 1) k++;
        } else {
            k--;
        }
        chmax(k_min, k);
    }
    cout << k_min << endl;
    cout << a << endl;
}
