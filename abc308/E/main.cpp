#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int mex(int a, int b, int c)
{
    // a,b,cのいずれとも一致しない最小の非負整数を返す
    if (a != 0 && b != 0 && c != 0)
        return 0;
    if (a != 1 && b != 1 && c != 1)
        return 1;
    if (a != 2 && b != 2 && c != 2)
        return 2;
    return 3;
}

int main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    string s;
    cin >> s;
    vvl M(n, vl(3, 0));
    vector<map<pair<int, int>, ll>> ME(n);
    vector<map<tuple<int, int, int>, ll>> MEX(n);
    ll ans = 0;
    if (s[0] == 'M')
        M[0][a[0]] += 1;
    rep(i, n - 1)
    {
        M[i + 1] = M[i];
        ME[i + 1] = ME[i];
        MEX[i + 1] = MEX[i];
        if (s[i + 1] == 'M')
        {
            M[i + 1][a[i + 1]] += 1;
        }
        else if (s[i + 1] == 'E')
        {
            ME[i + 1][{0, a[i + 1]}] += M[i + 1][0];
            ME[i + 1][{1, a[i + 1]}] += M[i + 1][1];
            ME[i + 1][{2, a[i + 1]}] += M[i + 1][2];
        }
        else if (s[i + 1] == 'X')
        {
            rep(j, 3) rep(k, 3)
            {
                MEX[i + 1][{j, k, a[i + 1]}] += ME[i + 1][{j, k}];
            }
        }
    }
    rep(i, 3) rep(j, 3) rep(k, 3)
    {
        ans += MEX[n - 1][{i, j, k}] * mex(i, j, k);
    }
    cout << ans << endl;
}
