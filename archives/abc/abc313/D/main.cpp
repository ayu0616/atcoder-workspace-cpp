#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, k;
    cin >> n >> k;
    vi res(n);
    rep(i, n)
    {
        vi x(k);
        rep(j,k) x[j] = (i+j)%n+1;
        cout<<"? "<<x<<endl;
        cin>>res[i];
    }
    map<pii, int> mp;
    rep(i, n)
    {
        mp[{i, (i + k) % n}] = (res[i] + res[(i + 1) % n])%2;
    }
    vi a(n);
}
