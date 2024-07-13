#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll R, G, B;
    string C;
    cin >> R >> G >> B >> C;
    if (C == "Red") {
        cout<<min(G, B)<<endl;
    }else if(C == "Green"){
        cout << min(R, B) << endl;
    } else {
        cout << min(R, G) << endl;
    }
}
