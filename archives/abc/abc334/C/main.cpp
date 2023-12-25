#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, K;
    cin >> N >> K;
    vi A(K);
    cin >> A;
    // rep(i, N)A[i]--;
    // vi L, R;
    // rep(i, N) {
    //     if(A.front()==i){
    //         L.push_back(i);
    //         A.erase(A.begin());
    //     }else{
    //         L.push_back(i);
    //         R.push_back(i);
    //     }
    // }
    // int ans = 0;
    // while(R.size()){
    //     int l = L.front();
    //     int r = R.front();
    //     L.erase(L.begin());
    //     R.erase(R.begin());
    //     ans += abs(l-r);
    // }
    // ans += L.size() / 2;
    if (K % 2 == 0) {
        int ans = 0;
        auto B = A;
        while (B.size()) {
            int l = B.front();
            B.erase(B.begin());
            int r = B.front();
            B.erase(B.begin());
            ans += abs(l - r);
        }
        cout << ans << endl;
    } else {
        vi L(K / 2), R(K / 2);
        rep(i, K - 1) {
            if (i % 2 == 0) {
                L[i / 2] = (A[i + 1] - A[i]);
            } else {
                R[i / 2] = (A[i + 1] - A[i]);
            }
        }
        vi L_sum(L.size() + 1), R_sum(R.size() + 1);
        L_sum[0] = 0;
        R_sum[0] = 0;
        rep(i, K / 2) {
            L_sum[i + 1] = L_sum[i] + L[i];
            R_sum[i + 1] = R_sum[i] + R[i];
        }
        int ans = 1e9;
        for (int i = 0;i<=K;i+=2) {
            int an = L_sum[i / 2] + R_sum[K / 2] - R_sum[i / 2];
            chmin(ans, an);
        }
        cout << ans << endl;
    }
}
