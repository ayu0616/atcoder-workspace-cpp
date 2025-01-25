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
    ll N, X;
    cin >> N >> X;
    vl V(N), A(N), C(N);
    rep(i, N) {
        cin >> V[i] >> A[i] >> C[i];
        V[i]--;
    }
    vpll v0, v1, v2;
    rep(i, N) {
        if (V[i] == 0) {
            v0.emplace_back(A[i], C[i]);
        } else if (V[i] == 1) {
            v1.emplace_back(A[i], C[i]);
        } else {
            v2.emplace_back(A[i], C[i]);
        }
    }
    // sort(ALL(v0), [](auto a, auto b) { return a.first / a.second < b.first / b.second; });
    // sort(ALL(v1), [](auto a, auto b) { return a.first / a.second < b.first / b.second; });
    // sort(ALL(v2), [](auto a, auto b) { return a.first / a.second < b.first / b.second; });
    vector v = {v0, v1, v2};
    // ll ok = 0, ng = 5000*2*100000+10;
    // while (ng - ok > 1) {
        // ll mid = (ok + ng) / 2;
        vector dp0(v0.size() + 1, vector(X + 1, 0LL));
        vector dp1(v1.size() + 1, vector(X + 1, 0LL));
        vector dp2(v2.size() + 1, vector(X + 1, 0LL));
        vector dp = {dp0, dp1, dp2};
        rep(i, 3) { dp[i][0][0] = 0; }
        rep(i, 3) {
            rep(j, v[i].size()) {
                rep(k, X + 1) {
                    if (k - v[i][j].second >= 0) {
                        chmax(dp[i][j + 1][k], dp[i][j][k - v[i][j].second] + v[i][j].first);
                    }
                    chmax(dp[i][j + 1][k], dp[i][j][k]);
                }
            }
        }
        ll minmax = 0;
        rep(i, X) {
            rep(j, X) {
                if (i + j > X) continue;
                chmax(minmax, min({dp[0][v0.size()][i], dp[1][v1.size()][j], dp[2][v2.size()][X - i - j]}));
            }
        }
        cout<<minmax<<endl;
        // if (minmax > mid) {
        //     ng = mid;
        // } else {
        //     ok = mid;
        // }
    // }
    // cout << ok << endl;
}
