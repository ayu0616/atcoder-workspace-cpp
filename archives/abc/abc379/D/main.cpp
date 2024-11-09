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
    ll Q;
    cin >> Q;
    vector<int> trees;
    vector<pair<int, ll>> T_list;
    T_list.emplace_back(0, 0);
    rep(i, Q) {
        int type;
        cin >> type;
        if (type == 1) {
            trees.emplace_back(i);
        } else if (type == 2) {
            ll T;
            cin >> T;
            T_list.emplace_back(i + 1, T_list.back().second + T);
        } else {
            ll H;
            cin >> H;
            ll l = -1, r = trees.size();
            while (r - l > 1) {
                ll m = (l + r) / 2;
                int idx = trees[m];
                ll tl = 0, tr = T_list.size();
                while (tr - tl > 1) {
                    ll tm = (tl + tr) / 2;
                    if (T_list[tm].first <= idx) {
                        tl = tm;
                    } else {
                        tr = tm;
                    }
                }
                ll height = T_list.back().second - T_list[tl].second;
                if (height >= H) {
                    l = m;
                } else {
                    r = m;
                }
            }
            cout << r << endl;
            trees = vi(trees.begin() + r, trees.end());
        }
    }
}
