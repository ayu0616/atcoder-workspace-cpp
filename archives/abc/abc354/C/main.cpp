#include <algorithm>
#include <iostream>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/segtree.hpp>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Card {
    ll A, C;
    ll idx;
    bool removed = false;
};

using S = ll;
S op(S a, S b) { return max(a, b); }
S e() { return -LL_INF; }

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vector<Card> cards(N);
    rep(i, N) {
        cin >> cards[i].A >> cards[i].C;
        cards[i].C *= -1;
        cards[i].idx = i;
    }
    auto cards_a = cards, cards_c = cards;
    sort(all(cards_a), [](const Card& a, const Card& b) { return a.A < b.A; });
    atcoder::segtree<S, op, e> seg_c(N);
    rep(i, N) { seg_c.set(i, cards_a[i].C); }
    rep(i, N) {
        ll c_max = seg_c.prod(i + 1, N);
        if (cards_a[i].C > c_max) {
            cards_a[i].removed = true;
        }
    }
    vl ans;
    rep(i, N) {
        if (cards_a[i].removed) {
            ans.push_back(cards_a[i].idx + 1);
        }
    }
    sort(all(ans));
    cout << ans.size() << endl;
    cout << ans << endl;
}
