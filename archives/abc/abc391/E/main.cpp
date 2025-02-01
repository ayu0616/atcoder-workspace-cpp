#include <string>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    string A;
    cin >> A;
    vs S;
    S.push_back(A);
    rep(N) {
        string B = S.back();
        string C = "";
        for (int i = 0; i < B.size(); i += 3) {
            int zero = 0, one = 0;
            for (int j = 0; j < 3; j++) {
                if (B[i + j] == '0')
                    zero++;
                else
                    one++;
            }
            if (zero > one)
                C += '0';
            else
                C += '1';
        }
        S.push_back(C);
    }
    char c = S.back()[0] == '0' ? '1' : '0';
    auto f = [&](auto &&f, int n, int i) -> int {
        if (n == 0) {
            return S[n][i] == c ? 0 : 1;
        }
        vi res;
        rep(j, 3) { res.push_back(f(f, n - 1, 3 * i + j)); }
        sort(all(res));
        return res[0] + res[1];
    };
    cout << f(f, N, 0) << endl;
}
