#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int heap_upper_bound(vector<ll> &v, ll x)
{
    int i = 0;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    while (l < v.size())
    {
        if (r < v.size())
        {
            if (v[l] < v[r])
            {
                if (v[l] <= x)
                {
                    i = l;
                    l = 2 * i + 1;
                    r = 2 * i + 2;
                }
                else
                    break;
            }
            else
            {
                if (v[r] <= x)
                {
                    i = r;
                    l = 2 * i + 1;
                    r = 2 * i + 2;
                }
                else
                    break;
            }
        }
        else
        {
            if (v[l] <= x)
            {
                i = l;
                l = 2 * i + 1;
                r = 2 * i + 2;
            }
            else
                break;
        }
    }
    return i;
}

int main()
{
    int N;
    string S;
    cin >> N >> S;
    vector<ll> x;
    ll ans = 0;
    int c = 0;
    rep(i, N-1){
        if(S[i]=='>'){
            c++;
            ans+=c;
        }else{
            c = 0;
        }
    }
    cout << ans << endl;
}
