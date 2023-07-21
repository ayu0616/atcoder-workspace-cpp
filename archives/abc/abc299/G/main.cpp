#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int n, m, a[200010];

int main()
{
    cin >> n >> m;
    vector<set<int>> cnt(m + 1);
    rep(i, n)
    {
        cin >> a[i];
        cnt[a[i]].insert(i);
    }
    set<int> ans;
    int ma = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i == 1)
        {
            ans.insert(*cnt[i].begin());
            ma = *cnt[i].begin();
        }
        else
        {
            auto it = cnt[i].upper_bound(ma);
            if (it == cnt[i].end())
            {
                ans.insert(*cnt[i].rbegin());
            }
            else
            {
                ans.insert(*it);
                ma = *it;
            }
        }
    }
    for (auto i : ans)
        cout << a[i] << " \n"[&i == &*ans.rbegin()];
}
