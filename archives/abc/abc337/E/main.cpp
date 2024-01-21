#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    int M = log2(N);
    if(N!=1<<M) M++;
    vvi drink(M);
    rep(i, N){
        int k = i+1;
        rep(j, M){
            if(k>>j&1){
                drink[j].push_back(k);
            }
        }
    }

    cout<<M<<endl;
    rep(i, M) cout<<drink[i].size() << " " << drink[i] << endl;

    string S;
    cin >> S;
    int X = 0;
    rep(i, M){
        if(S[i]=='1'){
            X += 1<<i;
        }
    }
    if(X==0) X = 1<<M;
    cout << X << endl;
}
