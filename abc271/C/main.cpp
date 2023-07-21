#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, buy_cnt = 0;
    cin >> n;
    deque<ll> a;
    set<ll> s;
    rep(i, n)
    {
        ll tmp;
        cin >> tmp;
        if (s.find(tmp) == s.end())
        {
            s.insert(tmp);
            a.push_back(tmp);
        }
        else
        {
            buy_cnt++;
        }
    }
    sort(all(a));
    int ans = 0;
    while (!a.empty()||buy_cnt>0)
    {
        ll x = a.front();
        if (x == ans + 1)
        {
            ans++;
            a.pop_front();
        }
        else
        {
            if (buy_cnt >= 2)
            {
                buy_cnt -= 2;
                a.push_front(ans + 1);
            }
            else if (buy_cnt == 1)
            {
                buy_cnt--;
                a.pop_back();
                a.push_front(ans + 1);
            }
            else if (a.size() >= 2)
            {
                a.pop_back();
                a.pop_back();
                a.push_front(ans + 1);
            }
            else
            {
                break;
            }
        }
    }
    cout << ans << endl;
}
