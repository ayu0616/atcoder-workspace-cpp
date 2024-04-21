#include <queue>
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
    ll N;
    double A, X, Y;
    cin >> N >> A >> X >> Y;
    map<ll, double> memo;
    memo[0] = 0;
    function<double(ll)> f = [&](ll n) {
        if (memo.count(n)) return memo[n];
        double fa = f(n / A)+X;
        double fb = 0;
        for(int i = 2;i<=6;i++) {
            fb += f(n / i);
        }
        fb /= 5;
        fb += Y*6/5;
        double res = min(fa, fb);
        return memo[n] = res;
    };
    cout << f(N) << endl;
}
