#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    ll ans = 0;
    rep(i,n){
        ans += s[i] - '0';
    }
    int last1=-1, last0=-1;
    rep(i,n){
        if(i>0&&i%2==0){
            if(s[i] == '1'){
                ans++;
            }else{
                ans--;
            }
        }
        if(s[i] == '1'){
            last1 = i;
        }else{
            last0 = i;
        }
    }
}
