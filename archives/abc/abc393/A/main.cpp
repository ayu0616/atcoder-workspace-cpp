#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    string S1, S2;
    cin >> S1>>S2;
    if(S1=="sick" && S2=="sick"){
        cout<<1<<endl;
    }else if(S1=="sick"&&S2=="fine"){
        cout<<2<<endl;
    }else if(S1=="fine"&&S2=="sick"){
        cout<<3<<endl;
    }else{
        cout<<4<<endl;
    }
}
