#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, M;
    cin >> N >> M;
    vl T(M), W(M), S(M);
    rep(i, M) cin >> T[i] >> W[i] >> S[i];
    vl ans = vl(N, 0);

    priority_queue<ll, vector<ll>, greater<ll>> queue;
    priority_queue<pll, vector<pll>, greater<pll>> eating;
    rep(i, N) queue.push(i);
    rep(i, M)
    {
        while (!eating.empty() && eating.top().first <= T[i])
        {
            queue.push(eating.top().second);
            eating.pop();
        }
        if (queue.empty())
            continue;
        ll now = queue.top();
        queue.pop();
        ans[now] += W[i];
        eating.push(pll(T[i] + S[i], now));
    }

    rep(i, N) cout << ans[i] << endl;
}
