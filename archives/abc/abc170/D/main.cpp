#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vi A(N);
    cin >> A;
    multiset<int> s;
    rep(i, N) s.insert(A[i]);

    int cnt = 0;
    while (s.size()) {
        int a = *s.begin();
        int a_cnt = s.count(a);
        if(a_cnt>1)cnt+=a_cnt;
        s.erase(a);
        if(s.size() == 0) break;
        for (int j = 1; a * j <= *s.rbegin(); j++) {
            auto it = s.find(a * j);
            while (it != s.end()) {
                s.erase(it);
                cnt++;
                it = s.find(a * j);
            }
            if(s.size() == 0) break;
        }
    }

    int ans = N - cnt;
    cout << ans << endl;
}
