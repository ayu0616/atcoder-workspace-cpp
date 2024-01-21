#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    int X = 0, Y = 0;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        X += x;
        Y += y;
    }
    if(X>Y)cout<<"Takahashi"<<endl;
    else if(X<Y)cout<<"Aoki"<<endl;
    else cout<<"Draw"<<endl;
}
