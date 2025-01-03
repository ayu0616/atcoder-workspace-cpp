#include <cassert>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Operation {
    int id;
    char type;
};

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl A(N), B(N);
    rep(i, N) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        if (A[i] > B[i]) {
            swap(A[i], B[i]);
        }
        if (B[i] - A[i] > N ) {
            A[i] += 2*N;
            swap(A[i], B[i]);
        }
    }
    vpll ab(N);
    rep(i, N) { ab[i] = {A[i], B[i]}; }
    sort(all(ab)), [](auto const &a, auto const &b) { return a.second > b.second; };
    vector<vector<Operation>> ops(4 * N);
    rep(i, N) {
        ll b = ab[i].second;
        ops[b].push_back({(int)i, 'B'});
    }
    rep(i, N) {
        ll a = ab[i].first;
        ops[a].push_back({(int)i, 'A'});
    }
    stack<int> st;
    rep(i, 4 * N) {
        for (auto &op : ops[i]) {
            if (op.type == 'A') {
                st.push(op.id);
            } else {
                if (st.empty()) {
                    assert(false);
                }
                int j = st.top();
                st.pop();
                if(op.id != j){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    if (!st.empty()) {
        assert(false);
    }
    cout << "No" << endl;
}
