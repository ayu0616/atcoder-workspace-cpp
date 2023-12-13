#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int A[9][9];
    rep(i, 9) rep(j, 9) cin >> A[i][j];
    bool ok = true;
    rep(i, 9)
    {
        set<int> s;
        rep(j, 9)
        {
            s.insert(A[i][j]);
        }
        if (s.size() != 9)
            ok = false;
    }
    rep(i, 9)
    {
        set<int> s;
        rep(j, 9)
        {
            s.insert(A[j][i]);
        }
        if (s.size() != 9)
            ok = false;
    }
    rep(i, 3)
    {
        rep(j, 3)
        {
            set<int> s;
            rep(k, 3)
            {
                rep(l, 3)
                {
                    s.insert(A[i * 3 + k][j * 3 + l]);
                }
            }
            if (s.size() != 9)
                ok = false;
        }
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
