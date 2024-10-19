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
    int L = 0, R = 1;
    int ans = 0;
    rep(Q) {
        char H;
        int T;
        cin >> H >> T;
        T--;
        int tmp = 1e9;
        int r = R, l = L;
        if (H == 'L') {
            // 時計回り
            int cnt = 0;
            while (true) {
                if (L == R) {
                    cnt = 1e9;
                    break;
                }
                if (T == L) break;
                L = (L + 1) % N;
                cnt++;
            }
            tmp = min(tmp, cnt);
            cnt = 0;
            L = l;
            // 反時計回り
            while (true) {
                if (L == R) {
                    cnt = 1e9;
                    break;
                }
                if (T == L) break;
                L = (L + N - 1) % N;
                cnt++;
            }
            tmp = min(tmp, cnt);
            assert(tmp != 1e9);
            ans += tmp;
            L = T;
        } else {
            // 反時計回り
            int cnt = 0;
            while (true) {
                if (L == R) {
                    cnt = 1e9;
                    break;
                }
                if (T == R) break;
                R = (R + N - 1) % N;
                cnt++;
            }
            tmp = min(tmp, cnt);
            cnt = 0;
            R = r;
            // 時計回り
            while (true) {
                if (L == R) {
                    cnt = 1e9;
                    break;
                }
                if (T == R) break;
                R = (R + 1) % N;
                cnt++;
            }
            tmp = min(tmp, cnt);
            assert(tmp != 1e9);
            ans += tmp;
            R = T;
        }
    }
    cout << ans << endl;
}
