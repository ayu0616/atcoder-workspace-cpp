#include <algorithm>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Bar {
    ll id, r, c, l;
    ll ans_r = -1;
};

bool operator<(const Bar &a, const Bar &b) {
    if (a.r == b.r) return a.c < b.c;
    return a.r < b.r;
}

int main() {
    cout << fixed << setprecision(18);
    ll H, W, N;
    cin >> H >> W >> N;
    vl R(N), C(N), L(N);
    rep(i, N) { cin >> R[i] >> C[i] >> L[i]; }
    vector<Bar> bars(N);
    rep(i, N) { bars[i] = {i, R[i] - 1, C[i] - 1, L[i]}; }
    sort(all(bars));
    reverse(all(bars));

    vector<set<pll>> v(H, set<pll>());
    for (auto &bar : bars) {
        ll l = -1, r = H;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            bool ok = true;
            if (v[m].empty()) {
                ok &= true;
            } else {
                auto it = v[m].lower_bound({bar.c, LL_INF});
                if (it != v[m].end()) {
                    auto [vc, vlen] = *it;
                    ll vc_end = vc + vlen;
                    ll barc_end = bar.c + bar.l;
                    ok &= vc_end <= bar.c || barc_end <= vc;
                    if (ok) {
                        auto nit = next(it);
                        if (nit != v[m].end()) {
                            auto [nvc, nvlen] = *nit;
                            ok &= bar.c + bar.l <= nvc;
                        }
                    }
                } else {
                    ok &= true;
                }
                if(ok && it != v[m].begin()) {
                    auto pit = prev(it);
                    auto [vc, vlen] = *pit;
                    ll vc_end = vc + vlen;
                    ll barc_end = bar.c + bar.l;
                    ok = vc_end <= bar.c || barc_end <= vc;
                }
            }
            if (ok) {
                l = m;
            } else {
                r = m;
            }
        }
        bar.ans_r = l;
        v[l].insert({bar.c, bar.l});
    }
    vl ans(N);
    rep(i, N) {
        Bar bar = bars[i];
        ans[bar.id] = bar.ans_r + 1;
    }
    rep(i, N) { cout << ans[i] << endl; }
}
