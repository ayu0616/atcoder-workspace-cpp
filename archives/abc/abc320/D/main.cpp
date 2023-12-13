#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

const string undecidable = "undecidable";

int main()
{
    ll N, M;
    cin >> N >> M;
    vl A(M), B(M), X(M), Y(M);
    vvl ans(N, vl(2, 0)), g(N);
    vector<bool> is_connected(N, false);
    is_connected[0] = true;
    map<pll, pll> diff;
    rep(i, M)
    {
        cin >> A[i] >> B[i] >> X[i] >> Y[i];
        A[i]--;
        B[i]--;
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
        diff[pll(A[i], B[i])] = pll(X[i], Y[i]);
        diff[pll(B[i], A[i])] = pll(-X[i], -Y[i]);
    }

    deque<ll> q;
    q.push_back(0);
    while (!q.empty())
    {
        ll now = q.front();
        q.pop_front();
        for (auto next : g[now])
        {
            if (!is_connected[next])
            {
                is_connected[next] = true;
                ans[next][0] = ans[now][0] + diff[pll(now, next)].first;
                ans[next][1] = ans[now][1] + diff[pll(now, next)].second;
                q.push_back(next);
            }
        }
    }
    rep(i, N)
    {
        if (is_connected[i])
        {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
        else
        {
            cout << undecidable << endl;
        }
    }
}
