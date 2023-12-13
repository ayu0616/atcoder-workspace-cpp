#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    string N;
    cin >> N;
    ll prev;
    if (N.size() == 1)
    {
        cout << "Yes" << endl;
        return 0;
    }
    prev = N[0] - '0';
    bool flag = true;
    for (int i = 1; i < N.size(); i++)
    {
        if (prev <= N[i] - '0')
        {
            flag = false;
            break;
        }
        prev = N[i] - '0';
    }
    if (flag)
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}
