#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vector<vector<string>> grid(N, vector<string>(N, "T"));
    int cnt = 0;
    int way = 0;
    int cx = 0, cy = 0;
    while (cnt < N * N - 1) {
        grid[cx][cy] = to_string(cnt + 1);
        cx += dx4[way];
        cy += dy4[way];
        if(cx<0||cy<0||cx>=N||cy>=N||grid[cx][cy]!="T"){
            cx -= dx4[way];
            cy -= dy4[way];
            way++;
            way%=4;
            cx += dx4[way];
            cy += dy4[way];
        }
        cnt++;
    }
    cout<<grid<<endl;
}
