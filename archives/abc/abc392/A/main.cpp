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
    vl A(3);
    cin >> A;
    vi order={0,1,2};
    do{
        if(A[order[0]]*A[order[1]] == A[order[2]]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }while(next_permutation(all(order)));
    cout<<"No"<<endl;
}
