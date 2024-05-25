#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/lazysegtree.hpp>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

bool is_dup(pll a, pll b) { return a.first <= b.first && b.first <= a.second; }

using S = set<ll>;
using F = set<ll>;
S op(S a, S b) {
    if (a.size() < b.size()) {
        swap(a, b);
    }
    for (ll x : b) {
        if (x < 0) {
            a.erase(-x);
        } else {
            a.insert(x);
        }
    }
    return a;
}
S e() { return {}; }
S mapping(F f, S x) { return op(x, f); }
F composition(F f, F g) { return op(f, g); }
F id() { return {}; }

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vpll lr(N);
    rep(i, N) { cin >> lr[i].first >> lr[i].second; }
    vl nums;
    rep(i, N) {
        nums.push_back(lr[i].first);
        nums.push_back(lr[i].second);
    }
    sort(all(nums));
    map<ll, ll> num2idx;
    int cur = 0;
    for (ll num : nums) {
        if (num2idx.find(num) == num2idx.end()) {
            num2idx[num] = cur++;
        }
    }
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(cur + 10);
    rep(i, N) { seg.apply(num2idx[lr[i].first], num2idx[lr[i].second]+1, {i+1}); }
    ll ans = 0;
    rep(i, N) {
        auto s = seg.prod(num2idx[lr[i].first], num2idx[lr[i].second]+1);
        ans += s.size() - 1;
        seg.apply(num2idx[lr[i].first], num2idx[lr[i].second]+1, {-(i+1)});
    }
    cout << ans << endl;
}
