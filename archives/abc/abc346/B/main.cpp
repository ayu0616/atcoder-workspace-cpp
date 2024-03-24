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
    int W,B;
    cin >> W >> B;
    string S = "wbwbwwbwbwbw";
    rep(i, 10) { S += S; }
    rep(i, S.size() - W - B) {
        int w = 0, b = 0;
        rep(j, W + B) {
            if (S[i + j] == 'w') w++;
            else b++;
        }
        if(w == W && b == B) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
