#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll a, n, ans;
int MAX = 1000001, dist[1000001];
deque<ll> q;

int main()
{
    cin >> a >> n;
    rep(i, MAX) dist[i] = -1;
    dist[a] = 1;
    q.push_back(a);
    while (!q.empty())
    {
        ll x = q.front();
        q.pop_front();
        // cout << x << endl;
        if (x == n)
        {
            break;
        }
        if (x * a < powl(10, 6) && dist[x * a] == -1)
        {
            dist[x * a] = dist[x] + 1;
            q.push_back(x * a);
        }
        if (x >= 10 && x % 10 != 0)
        {
            ll d = log10l(x);
            ll b = x % 10;
            ll tmp = x / 10;
            tmp += b * powl(10, d);
            if (dist[tmp] == -1)
            {
                dist[tmp] = dist[x] + 1;
                q.push_back(tmp);
            }
        }
    }
    cout << dist[n] << endl;
}
