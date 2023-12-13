#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N, Q;
    cin >> N >> Q;
    vi C(N);
    rep(i, N)
    {
        cin >> C[i];
        C[i]--;
    }
    vector<set<int>> boxes(N);
    rep(i, N) boxes[i].insert(C[i]);
    while (Q--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (boxes[a].size() > boxes[b].size())
        {
            swap(boxes[a], boxes[b]);
        }
        for (auto x : boxes[a])
            boxes[b].insert(x);
        boxes[a].clear();
        cout << boxes[b].size() << endl;
    }
}
