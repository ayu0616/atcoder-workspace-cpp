#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    deque<char> sq, tq;
    rep(i, s.size()) sq.push_back(s[i]);
    rep(i, t.size()) tq.push_back(t[i]);
    string ans = "Yes";
    string at = "atcoder";
    while (!sq.empty() && !tq.empty())
    {
        char si = sq.front(), ti = tq.front();
        if (si == ti)
        {
            sq.pop_front();
            tq.pop_front();
        }
        else if (si > ti)
        {
            if (tq.back() == '@' && at.find(si) != string::npos)
            {
                sq.pop_front();
                tq.pop_back();
            }
            else
            {
                ans = "No";
                break;
            }
        }
        else if (si < ti)
        {
            if (sq.back() == '@' && at.find(ti) != string::npos)
            {
                sq.pop_back();
                tq.pop_front();
            }
            else
            {
                ans = "No";
                break;
            }
        }
    }
    cout << ans << endl;
}
