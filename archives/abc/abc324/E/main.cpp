#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll count(string &s, string &t){
    ll res = 0;
    for(auto c:s){
        if(res>=t.size()) break;
        if(c==t[res]) res++;
    }
    return res;
}

int main()
{
    ll N;
    string T;
    cin >> N >> T;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    vector<ll> front(N, 0), back(N, 0);
    rep(i, N)
    {
        front[i] = count(S[i], T);
    }
    reverse(all(T));
    rep(i, N){
        reverse(all(S[i]));
        back[i] = count(S[i], T);
    }
    sort(all(back));
    vector<ll> back_cnt(500001, 0);
    rep(i, N) back_cnt[back[i]]++;
    ll ans = 0;
    rep(i, N)
    {
        for (ll j = T.size() - front[i]; j <= T.size(); j++)
        {
            ans += back_cnt[j];
        }
    }
    cout << ans << endl;
}
