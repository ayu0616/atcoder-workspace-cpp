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
    int H, W, K;
    cin >> H >> W >> K;
    vs S(H);
    cin >> S;

    auto pos_to_index = [&](int i, int j) { return i * W + j; };

    set<vi> st;

    map<int, bool> visited;
    function<void(int, int, vi&)> dfs = [&](int i, int j, vi& path) {
        if (i < 0 || i >= H || j < 0 || j >= W) return;
        if (S[i][j] == '#') return;
        int idx = pos_to_index(i, j);
        if (visited[idx]) return;
        visited[idx] = true;

        path.push_back(idx);
        const int depth = path.size();
        if (depth == K + 1) {
            st.insert(path);
            visited[idx] = false;
            path.pop_back();
            return;
        }

        assert(depth <= K);

        dfs(i + 1, j, path);
        dfs(i - 1, j, path);
        dfs(i, j + 1, path);
        dfs(i, j - 1, path);

        visited[idx] = false;
        path.pop_back();
    };

    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') continue;
            vi path;
            dfs(i, j, path);
            visited.clear();
        }
    }

    cout << st.size() << endl;
}
