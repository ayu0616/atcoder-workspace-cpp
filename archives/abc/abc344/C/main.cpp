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
    int N;
    cin >> N;
    vi A(N);
    cin >> A;
    int M;
    cin >> M;
    vi B(M);
    cin >> B;
    int L;
    cin >> L;
    vi C(L);
    cin >> C;
    int Q;
    cin >> Q;
    vi X(Q);
    cin >> X;

    sort(all(A));
    sort(all(B));
    sort(all(C));

    set<int> S;

    rep(i, N) rep(j, M) rep(k, L) { S.insert(A[i] + B[j] + C[k]); }

    for (auto x : X) {
        cout << (S.count(x) ? "Yes" : "No") << endl;
    }
}
