#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int n;
const int MAX_M = 2 * 1000;
vi p;

vi sorting(vi &p, int i, int j)
{
    vi Q(n - 2);
    rep(k, n)
    {
        if (k < i)
            Q[k] = p[k];
        else if (k > i + 1)
            Q[k - 2] = p[k];
    }
    vi new_p(n);
    rep(k, j)
    {
        new_p[k] = Q[k];
    }
    new_p[j] = p[i];
    new_p[j + 1] = p[i + 1];
    rep2(k, j + 2, n)
    {
        new_p[k] = Q[k - 2];
    }
    return new_p;
}

int main()
{
    cin >> n;
    p = vi(n);
    rep(i, n) cin >> p[i];
    rep(i, n) p[i]--;

    int cnt = 0;
    vi ans;
    while (!is_sorted(p.begin(), p.end()))
    {
        if (cnt > 2000)
        {
            cout << "No" << endl;
            return 0;
        }
        cnt++;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (i == j)
                    continue;
                vi q = sorting(p, i, j);
                if (is_sorted(q.begin(), q.end()))
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    p = q;
                    break;
                }
            }
            if (is_sorted(p.begin(), p.end()))
                break;
        }
    }
    cout << "Yes" << endl;
    cout << ans.size() / 2 << endl;
    for (int i = 0; i < ans.size(); i += 2)
    {
        cout << ans[i] + 1 << " " << ans[i + 1] << endl;
    }
    return 0;
}
