#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vl b;

int main() {
    ll N, M, L;
    cin >> N >> M >> L;
    vl a(N);
    b.resize(M);
    cin >> a >> b;
    bool (*f)(int, int) = [](int x, int y) { return b[x] < b[y]; };
    set<int, bool (*)(int, int)> s(f);
    rep(i, M) s.insert(i);
    vector<set<int>> no(N);
    while (L--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        no[x].insert(y);
    }
    ll ans = 0;
    rep(i, N) {
        ll x = a[i];
        auto it = s.rbegin();
        while(no[i].find(*it) != no[i].end()) it++;
        int j = *it;
        ll y = b[j];
        chmax(ans, x + y);
    }
    cout << ans << endl;
}
