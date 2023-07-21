#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(n);
    int cnt = 0;

    rep(i, n)
    {
        vi sm, lg;
        rep(j, a.size())
        {
            if (a[0] > a[j])
            {
                sm.push_back(a[j]);
            }
            if (a[0] < a[j])
            {
                lg.push_back(a[j]);
            }
        }
        int eq = a.size() * (a.size() + 1) / 2 - sm.size() - lg.size();
        if (k <= cnt + sm.size())
        {
            sort(sm.begin(), sm.end());
            int sm_i = k - cnt;
            vi::iterator a_sm_i = find(a.begin(), a.end(), sm[sm_i - 1]);
            reverse(a.begin(), a_sm_i);
            rep(j, a.size()) b[i + j] = a[j];
            break;
        }
        else if (k <= cnt + sm.size() + eq)
        {
            b[i] = a[0];
            a.erase(a.begin());
            cnt += sm.size();
        }
        else
        {
            sort(lg.begin(), lg.end());
            int lg_i = k - cnt - sm.size() - eq;
            vi::iterator a_lg_i = find(a.begin(), a.end(), lg[lg_i - 1]);
            reverse(a.begin(), a_lg_i);
            rep(j, a.size()) b[i + j] = a[j];
            break;
        }
    }
    cout << b << endl;

    // vvi revs;
    // rep(i, n) rep2(j, i, n)
    // {
    //     if (i == j)
    //     {
    //         revs.push_back(a);
    //     }
    //     else
    //     {
    //         vi tmp = revs.back();
    //         vi rev(n);
    //         rep(l, i) { rev[l] = tmp[l]; }
    //         rev[i] = tmp[j];
    //         rep(l, j - i)
    //         {
    //             rev[l + i + 1] = tmp[l + i];
    //         }
    //         rep2(l, j - i + 1, n)
    //         {
    //             rev[l] = tmp[l];
    //         }
    //         revs.push_back(rev);
    //     }
    // }

    // sort(revs.begin(), revs.end());
    // cout << revs[k - 1] << endl;
}
