#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvi ans(h, vi(w));
    int x = 0, y = 0;
    rep(i, n)
    {
        while(a[i]--){
            ans[y][x] = i + 1;
            if(y%2==0){
                x++;
                if(x==w){
                    x--;
                    y++;
                }
            }else{
                x--;
                if(x==-1){
                    x++;
                    y++;
                }
            }
        }
    }
    rep(i,h)rep(j,w)cout<<ans[i][j]<<" \n"[j==w-1];
}
