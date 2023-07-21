#include "../../lib.hpp"

const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

using mint = static_modint<MOD>;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> yakusuu;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            yakusuu.push_back(i);
            yakusuu.push_back(n / i);
        }
    }
    yakusuu.erase(n);

    vector<int> t_not_work_idx;
    rep(i,n)if(s[i]=='.')t_not_work_idx.push_back(i);

    mint ans = 0;

    for(auto m:yakusuu){
        vector<bool> free(m,true);
        rep(i,n/m){
            rep(j,m){
                if(s[i*m+j]=='#')free[j]=false;
            }
        }

    }
}
