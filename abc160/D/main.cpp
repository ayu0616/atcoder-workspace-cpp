#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n,x,y;
    cin >> n >> x >> y;
    vector<int> ans(n, 0);
    for (int i = 0; i < n-1;i++){
        for (int j = i + 1; j < n;j++){
            int dist=min(j - i, abs(x - 1 - i) + 1 + abs(y - 1 - j));
            ans[dist]++;
        }
    }
    for (int i = 1; i < n;i++){
        cout << ans[i] << endl;
    }
}
