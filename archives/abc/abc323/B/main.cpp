#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N;
    cin >> N;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    vector<ll> v(N);
    rep(i, N)
    {
        rep(j, N)
        {
            if (S[i][j] == 'o')
                v[i]++;
        }
    }
    vector<pll> ans;
    rep(i, N){
        ans.push_back({v[i], -i});
    }
    sort(all(ans));
    reverse(all(ans));
    for(auto&& i : ans){
        cout << -i.second + 1 << " \n"[&i == &ans.back()];
    }
}
