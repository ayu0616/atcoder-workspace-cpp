#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    string sd, t;
    cin >> sd >> t;
    int s_size = sd.size(), t_size = t.size();
    for (int i = s_size - t_size; i >= 0; i--)
    {
        bool ok = true;
        rep(j, t_size)
        {
            if (sd[i + j] == t[j])
                continue;
            if (sd[i + j] == '?')
                continue;
            ok = false;
            break;
        }
        if (ok)
        {
            rep(j, t_size)
            {
                sd[i + j] = t[j];
            }
            rep(j, s_size)
            {
                if (sd[j] == '?')
                    sd[j] = 'a';
            }
            cout << sd << endl;
            return 0;
        }
    }
    cout << "UNRESTORABLE" << endl;
}
