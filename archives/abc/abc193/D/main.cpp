#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

bool is_takahashi_win(vector<int> &t, vector<int> &a)
{
    vector<int> tm(10, 0), am(10, 0);
    rep(i, 5)
    {
        tm[t[i]]++;
        am[a[i]]++;
    }
    int s = 0;
    for (int i = 1; i <= 9; i++)
    {
        s += i * pow(10, tm[i]);
        s -= i * pow(10, am[i]);
    }
    return s > 0;
}

int main()
{
    ll k;
    string ss, ts;
    cin >> k >> ss >> ts;
    vector<int> t, a;
    rep(i, 4)
    {
        t.push_back(ss[i] - '0');
        a.push_back(ts[i] - '0');
    }
    t.push_back(0), a.push_back(0);
    vector<ll> remain(10, k);
    rep(i, 4)
    {
        remain[t[i]]--;
        remain[a[i]]--;
    }

    double ans = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            if (remain[i] == 0 || remain[j] == 0 || (i == j && remain[i] == 1))
                continue;
            t[4] = i, a[4] = j;
            if (is_takahashi_win(t, a))
            {
                if (i == j)
                    ans += remain[i] * (remain[j] - 1);
                else
                    ans += remain[i] * remain[j];
            }
        }
    cout << ans / ((k * 9 - 8) * (k * 9 - 9)) << endl;
}
