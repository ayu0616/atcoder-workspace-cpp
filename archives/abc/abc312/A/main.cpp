#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    vector<string> c = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    string s;
    cin >> s;
    for (auto &&i : c)
    {
        if (i == s)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
