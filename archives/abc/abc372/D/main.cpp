#include <algorithm>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vi H(N);
    cin >> H;
    vi ans(N);
    set<int> cur;
    for (int i = N - 1; i >= 0; i--) {
        ans[i] = cur.size();
        ll h = H[i];
        cur.insert(h);
        while (cur.size() && *cur.begin() < h) {
            cur.erase(cur.begin());
        }
    }
    cout << ans << endl;
}
