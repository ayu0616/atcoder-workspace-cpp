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
    ll N, M;
    cin >> N >> M;
    vl A(M);
    cin >> A;
    for (auto &a : A) a--;
    vl B(N);
    iota(all(B), 0);
    map<int, vector<int>> mp;
    int cur = 0;
    rep(i, M) {
        int next = cur;
        if (A[i] == cur) {
            next++;
        } else if (A[i] + 1 == cur) {
            next--;
        }
            swap(mp[A[i]], mp[A[i] + 1]);
        mp[cur].push_back(i);
        // debug(i);
        // for(auto x:mp){
        //     cerr << x.first << ":";
        //     for(auto y:x.second){
        //         cerr << y << " ";
        //     }
        //     cerr << endl;
        // }
        // cerr<<endl;
        cur = next;
    }
    vi ans(M);
    for (auto x : mp) {
        for (auto y : x.second) {
            ans[y] = x.first;
        }
    }
    for (auto x : ans) {
        cout << x + 1 << endl;
    }
}
