#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N;
    cin >> N;
    vector<string> S(N);
    cin >> S;
    vvi cs_h(N);
    vi cs_v(N);
    rep(i, N)
    {
        rep(j, N)
        {
            if (S[i][j] == 'o')
                cs_h[i].push_back(j);
        }
    }
    rep(j, N)
    {
        rep(i, N)
        {
            if (S[i][j] == 'o')
                cs_v[j]++;
        }
    }

    ll ans = 0;
    rep(i, N) rep(j, cs_h[i].size())
    {
        int x = cs_h[i][j];
        ans += (cs_v[x] - 1) * (cs_h[i].size() - 1);
    }

    cout << ans << endl;
}
