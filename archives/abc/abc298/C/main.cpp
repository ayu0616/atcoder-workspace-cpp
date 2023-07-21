#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n, q;

int main()
{
    cin >> n >> q;
    vector<priority_queue<ll, vector<ll>, greater<ll>>> v(200000);
    vector<set<ll>> s(200000);
    int type;
    rep(i, q)
    {
        cin >> type;
        if (type == 1)
        {
            ll a, b;
            cin >> a >> b;
            a--, b--;
            v[b].push(a);
            s[a].insert(b);
        }
        else if (type == 2)
        {
            ll a;
            cin >> a;
            a--;
            auto tmp = v[a];
            while (!tmp.empty())
            {
                cout << tmp.top() + 1 << " \n"[tmp.size() == 1];
                tmp.pop();
            }
        }
        else
        {
            ll a;
            cin >> a;
            a--;
            ll cnt = 1;
            for (auto x : s[a])
            {
                cout << x + 1 << " \n"[cnt == s[a].size()];
                cnt++;
            }
        }
    }
}
