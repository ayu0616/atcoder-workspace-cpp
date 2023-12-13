#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, M;
    cin >> N >> M;
    vl A(M);
    vl score(N, 0);
    vector<string> S(N);
    rep(i, M) cin >> A[i];
    rep(i, N) cin >> S[i];
    vector<pll> v;
    rep(i, M) v.push_back({A[i], i});
    sort(all(v));
    reverse(all(v));
    rep(i, N)
    {
        score[i] += i + 1;
        rep(j, M)
        {
            if (S[i][j] == 'o')
            {
                score[i] += A[j];
            }
        }
    }
    ll ma = *max_element(all(score));
    rep(i, N)
    {
        if (score[i] == ma)
        {
            cout << 0 << endl;
        }
        else
        {
            ll ans = 0, cur = score[i];
            rep(j, M)
            {
                if (S[i][v[j].second] == 'x')
                {
                    cur += v[j].first;
                    ans++;
                    if (cur > ma)
                    {
                        cout << ans << endl;
                        break;
                    }
                }
            }
        }
    }
}
