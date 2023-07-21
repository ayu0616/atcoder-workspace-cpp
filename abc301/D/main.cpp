#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll ans, n;
// void solve(vi &a, int i, ll cnt)
// {
//     if (i >= a.size())
//         return;
//     ll two_a = powl(2, a[i]);
//     ll bigger = cnt + two_a;
//     if (!(ans > cnt + two_a - 1))
//     {
//         solve(a, i + 1, cnt);
//     }
//     if (!(bigger > n))
//     {
//         ans = max(ans, bigger);
//         solve(a, i + 1, bigger);
//     }
// }

int main()
{
    string s;
    cin >> s;
    cin >> n;
    // bitset<64> bs(n);
    // string bin = bs.to_string();

    vi question;

    ans = 0;
    rep(i, s.size())
    {
        if (s[i] == '1')
        {
            ans += powl(2, s.size() - i - 1);
        }
        else if (s[i] == '?')
        {
            question.push_back(s.size() - i - 1);
        }
    }
    if (ans > n)
    {
        cout << -1 << endl;
        return 0;
    }
    sort(question.begin(), question.end());
    reverse(question.begin(), question.end());
    // solve(question, 0, ans);
    rep(i, question.size())
    {
        ll two_a = powl(2, question[i]);
        ll bigger = ans + two_a;
        if (bigger <= n)
        {
            ans = bigger;
        }
    }
    cout << ans << endl;
}
