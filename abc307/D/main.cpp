#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int n;
string s;

int main()
{
    cin >> n >> s;
    deque<int> q, q1;
    string ans = s;
    vector<pair<int, int>> skip_i;

    rep(i, n)
    {
        if (s[i] == '(')
        {
            q.push_back(i);
        }
        else if (s[i] == ')')
        {
            if (!q.empty())
            {
                if (!skip_i.empty()&&q.back() < skip_i.back().first && skip_i.back().second < i)
                {
                    skip_i.back().first = q.back();
                    skip_i.back().second = i;
                }
                else
                {
                    skip_i.push_back({q.back(), i});
                }
                q.pop_back();
            }
        }
    }

    for (auto &p : skip_i)
    {
        rep2(j, p.first, p.second + 1)
        {
            ans[j] = ' ';
        }
    }

    rep(i, n)
    {
        if (ans[i] != ' ')
        {
            cout << ans[i];
        }
    }
    cout << endl;
}
