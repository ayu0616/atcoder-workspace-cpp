#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    ll N, K;
    cin >> N >> K;
    vl X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    map<ll, int> x_map, y_map;
    rep(i, N) {
        x_map[X[i]]++;
        y_map[Y[i]]++;
    }
    set<ll> x_set, y_set;
    for (auto p : x_map) x_set.insert(p.first);
    for (auto p : y_map) y_set.insert(p.first);
    ll x_len = *x_set.rbegin() - *x_set.begin();
    ll y_len = *y_set.rbegin() - *y_set.begin();
    if (x_len < y_len) {
        swap(x_len, y_len);
        swap(x_map, y_map);
        swap(x_set, y_set);
    }

    while (K > 0) {
        ll x_min = *x_set.begin();
        ll x_max = *x_set.rbegin();
        ll x_min_cnt = x_map[x_min];
        ll x_max_cnt = x_map[x_max];
        if (x_set.size() == 1) break;
        if (x_min_cnt < x_max_cnt) {
            ll x_min2 = *next(x_set.begin());
            ll k = x_min_cnt * (x_min2 - x_min);
            x_set.erase(x_min);
            x_map[x_min] = 0;
            x_map[x_min2] += x_min_cnt;
            K -= k;
        } else {
            ll x_max2 = *prev(x_set.rbegin());
            ll k = x_max_cnt * (x_max - x_max2);
            x_set.erase(x_max);
            x_map[x_max] = 0;
            x_map[x_max2] += x_max_cnt;
            K -= k;
        }
        x_len = *x_set.rbegin() - *x_set.begin();
        y_len = *y_set.rbegin() - *y_set.begin();
        if (x_len < y_len) {
            swap(x_len, y_len);
            swap(x_map, y_map);
            swap(x_set, y_set);
        }
    }
    x_len = *x_set.rbegin() - *x_set.begin();
    y_len = *y_set.rbegin() - *y_set.begin();
    cout << max(x_len, y_len) << endl;
}
