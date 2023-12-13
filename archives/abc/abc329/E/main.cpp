#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N, M;
    string S, T;
    cin >> N >> M >> S >> T;
    queue<int> q;
    vector<bool> used(N, false);
    auto check = [&](int i)
    {
        if (used[i])
            return;
        bool good = true;
        rep(j, M) good &= (S[i + j] == T[j] || S[i + j] == '#');
        if (good)
        {
            q.push(i);
            used[i] = true;
        }
    };
    rep(i, N - M + 1) check(i);
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        rep(j, M) S[i + j] = '#';
        rep(j, max(i - M + 1, 0), min(i + M, N - M + 1)) { check(j); }
    }
    cout << (S == string(N, '#') ? "Yes" : "No") << endl;
}
