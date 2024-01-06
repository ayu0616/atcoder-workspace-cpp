#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vector<tuple<int, int, int>> ans;
    for (int x = 0; x <= N; x++)
        for (int y = 0; y <= N; y++)
            for (int z = 0; z <= N; z++)
                if (x + y + z <= N) ans.emplace_back(x, y, z);

    sort(ans.begin(), ans.end());
    for (auto [x, y, z] : ans) cout << x << " " << y << " " << z << endl;
}
