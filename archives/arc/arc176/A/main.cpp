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
    ll N, M;
    cin >> N >> M;
    vl A(M), B(M);
    vvl row(N), col(N);
    map<pll, bool> mp;
    vpll ans;
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        row[A[i]].push_back(B[i]);
        col[B[i]].push_back(A[i]);
        mp[{A[i], B[i]}] = true;
    }
    rep(i, N) {
        rep(j, M) {
            int jj = j + i;
            row[i].push_back(jj % N);
            col[jj % N].push_back(i);
        }
    }
    // for (auto i : A) {
    //     rep(j, N) {
    //         if (mp[{i, j}]) continue;
    //         row[i].push_back(j);
    //         col[j].push_back(i);
    //         mp[{i, j}] = true;
    //         if(row[i].size() == M) break;
    //     }
    // }
    // rep(i, N) {
    //     int j = 0;
    //     while (j < N && row[i].size() < M) {
    //         if (mp[{i, j}] || col[j].size() == M) {
    //             j++;
    //             continue;
    //         }
    //         row[i].push_back(j);
    //         col[j].push_back(i);
    //         mp[{i, j}] = true;
    //         j++;
    //     }
    // }
    // rep(i, N) {
    //     for (auto j : row[i]) {
    //         ans.push_back({i, j});
    //     }
    // }
    sort(all(ans));
    cout << ans.size() << endl;
    rep(i, ans.size()) { cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl; }
}
