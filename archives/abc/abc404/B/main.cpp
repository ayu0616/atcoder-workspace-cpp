#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int distance(const vs& s, const vs& t) {
    int n = s.size();
    int m = s[0].size();
    int d = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] != t[i][j]) {
                d++;
            }
        }
    }
    return d;
}

void rotate90(vector<string>& s) {
    int n = s.size();
    vector<string> t(n, string(n, ' '));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            t[j][n - 1 - i] = s[i][j];
        }
    }
    s = t;
}

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vs S(N), T(N);
    cin >> S >> T;

    int ans = INT_INF;
    chmin(ans, distance(S, T));
    rotate90(S);
    chmin(ans, distance(S, T) + 1);
    rotate90(S);
    chmin(ans, distance(S, T) + 2);
    rotate90(S);
    chmin(ans, distance(S, T) + 3);
    cout << ans << endl;
}
