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
    int N, Q;
    cin >> N;
    vi A(N);
    cin >> A >> Q;

    map<int, int> prev;
    map<int, int> next;

    next[-1] = A[0];
    prev[A[0]] = -1;

    rep(i, 1, N) {
        prev[A[i]] = A[i - 1];
        next[A[i - 1]] = A[i];
    }

    rep(Q) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            int ne = next[x];
            next[x] = y;
            next[y] = ne;
            prev[y] = x;
            prev[ne] = y;
        } else {
            int x;
            cin >> x;
            int ne = next[x];
            int pr = prev[x];
            next[pr] = ne;
            prev[ne] = pr;
            next[x] = 0;
            prev[x] = 0;
            next.erase(x);
            prev.erase(x);
        }
    }
    vi ans;
    int cur = -1;
    while (cur != 0) {
        ans.push_back(cur);
        cur = next[cur];
    }
    cout << vi(ans.begin()+1, ans.end()) << endl;
}
