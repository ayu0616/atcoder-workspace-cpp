#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int N, K, P;
struct Plan {
    ll C;
    vi A;
};

// P+1進数の各桁を取得
vi getDigits(int n) {
    int base = P + 1;
    vi res(K, 0);
    int i = 0;
    while (n > 0) {
        res[i] = n % base;
        n /= base;
        i++;
    }
    return res;
}

int to_decimal(vi digits) {
    int res = 0;
    int base = P + 1;
    rep(i, digits.size()) { res += digits[i] * pow(base, i); }
    return res;
}

int main() {
    cin >> N >> K >> P;
    vector<Plan> plans(N);
    rep(i, N) {
        Plan plan;
        cin >> plan.C;
        plan.A.resize(K);
        cin >> plan.A;
        plans[i] = plan;
    }

    int state_num = pow(P + 1, K);
    vvl dp(N + 1, vl(state_num, LL_INF));
    rep(i, N + 1) { dp[i][0] = 0; }

    rep(i, N) {
        rep(j, state_num) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            vi p_list = getDigits(j);
            rep(k, K) { p_list[k] = min(p_list[k] + plans[i].A[k], P); }
            int nj = to_decimal(p_list);
            chmin(dp[i + 1][nj], dp[i][j] + plans[i].C);
        }
    }
    if (dp[N][state_num - 1] == LL_INF)
        cout << -1 << endl;
    else
        cout << dp[N][state_num - 1] << endl;
}
