#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    set<string> s;
    rep(i, n)
    {
        string tmp1;
        cin >> tmp1;
        string tmp2 = tmp1;
        reverse(all(tmp1));
        if (s.find(tmp1) == s.end() && s.find(tmp2) == s.end())
        {
            s.insert(tmp1);
        }
    }
    cout << s.size() << endl;
}
