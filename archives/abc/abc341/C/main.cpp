#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

map<char, int> dx = {{'L', -1}, {'R', 1}, {'U', 0}, {'D', 0}};
map<char, int> dy = {{'L', 0}, {'R', 0}, {'U', -1}, {'D', 1}};

int main() {
    cout << fixed << setprecision(18);
    int H, W, N;
    cin >> H >> W >> N;
    string T;
    vs S(H);
    cin >> T >> S;
    set<pii> st;
    rep(h, H) rep(w, W) {
        if (S[h][w] == '#') continue;
        bool ok = true;
        int nh = h, nw = w;
        for (auto t : T) {
            nh += dy[t];
            nw += dx[t];
            if (nh < 0 || nh >= H || nw < 0 || nw >= W || S[nh][nw] == '#') {
                ok = false;
                break;
            }
        }
        if (ok) st.insert({nh, nw});
    }
    cout << st.size() << endl;
}
