#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<pii> heads(N);
    rep(i, N)heads[i] = {i+1, 0};
    reverse(all(heads));
    while (Q--) {
        int type;
        cin >> type;
        if(type==1){
            char C;
            cin>>C;
            pii head = heads.back();
            if(C=='R'){
                head.first++;
                heads.push_back(head);
            }else if(C=='L'){
                head.first--;
                heads.push_back(head);
            } else if(C=='U'){
                head.second++;
                heads.push_back(head);
            } else if(C=='D'){
                head.second--;
                heads.push_back(head);
            }
        }else{
            int p;
            cin>>p;
            pii pos = *(heads.end() - p);
            cout<<pos.first<<" "<<pos.second<<endl;
        }
    }
}
