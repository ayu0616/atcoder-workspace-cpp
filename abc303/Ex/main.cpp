#include "../../lib.hpp"

const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

using mint = static_modint<MOD>;

int main()
{
    int n, k;
    vector<int> s;
    cin >> n >> k;
    rep(i,k){
        int si;
        cin>>si;
        s.push_back(si);
    }

    int sum_deg = 2 * n - 2;

    rep(i,k){
        for (int j = 1; j <= min(n, sum_deg / s[i]);j++){
            
        }
    }
}
