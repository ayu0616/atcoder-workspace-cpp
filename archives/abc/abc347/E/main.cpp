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
    ll N, Q;
    cin >> N >> Q;
    vl x(Q), A(N, 0);
    cin >> x;
    rep(i, Q) x[i]--;
    set<int> S;
    vl s_size;
    s_size.push_back(0);
    vl started(N, -1);
    rep(i, Q) {
        if (S.count(x[i])) {
            S.erase(x[i]);
            A[x[i]] += s_size.back() - s_size[started[x[i]]];
        } else {
            S.insert(x[i]);
            started[x[i]] = i;
        }
        s_size.push_back(s_size.back() + S.size());
    }
    for (auto s : S) {
        A[s] += s_size.back() - s_size[started[s]];
    }
    cout << A << endl;
}
