#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N;
    string S;
    cin >> N >> S;

    rep(i, N-2){
        if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C'){
            cout << i+1 << endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
