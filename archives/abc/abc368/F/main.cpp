#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

map<ll, vector<ll>> memo;
/*  divisor(n)
    入力：整数 n
    出力：nのすべての約数
    計算量：O(√n)
*/
vector<long long> divisor(long long n) {
    if (memo.count(n)) return memo[n];
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());  // 昇順に並べる
    return memo[n] = ret;
}

map<int, int> grundy_memo;
int grundy(int x) {
    if (grundy_memo.count(x)) return grundy_memo[x];
    set<int> s;
    auto res = divisor(x);
    for (int y : res) {
        if (y == x) continue;
        s.insert(grundy(y));
    }
    int g = 0;
    while (s.count(g)) g++;
    return grundy_memo[x] = g;
}

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vi A(N);
    cin >> A;
    int x = 0;
    for (int a : A) {
        x ^= grundy(a);
    }
    cout << (x == 0 ? "Bruno" : "Anna") << endl;
}
