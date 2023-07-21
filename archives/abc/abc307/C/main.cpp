#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int ha, wa, hb, wb, hx, wx;
vector<string> a, b, x, c;
vpii ap, bp, ok_ij;
set<pii> xp;

bool is_x(vector<string> &c)
{
    rep(i, 30 - hx) rep(j, 30 - wx)
    {
        bool ok = true;
        rep(k, 30) rep(l, 30)
        {
            if (i <= k && k < i + hx && j <= l && l < j + wx)
            {
                if (c[k][l] != x[k - i][l - j])
                    ok = false;
            }
            else if (c[k][l] == '#')
            {
                ok = false;
            }
        }
        if (ok)
            return true;
    }
    return false;
}

int main()
{
    cin >> ha >> wa;
    a.resize(ha);
    rep(i, ha) cin >> a[i];
    cin >> hb >> wb;
    b.resize(hb);
    rep(i, hb) cin >> b[i];
    cin >> hx >> wx;
    x.resize(hx);
    rep(i, hx) cin >> x[i];

    rep(i, ha) rep(j, wa) if (a[i][j] == '#') ap.push_back({i, j});
    rep(i, hb) rep(j, wb) if (b[i][j] == '#') bp.push_back({i, j});
    rep(i, hx) rep(j, wx) if (x[i][j] == '#') xp.insert({i, j});

    rep2(i, -10, 11)
    {
        rep2(j, -10, 11)
        {
            bool ok = true;
            auto xp_cp = xp;
            for (auto &p : ap)
            {
                int yi = p.first + i;
                int xi = p.second + j;
                if (0 <= yi && yi < hx && 0 <= xi && xi < wx && x[yi][xi] == '#')
                {
                    xp_cp.erase({yi, xi});
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                rep2(k, -10, 11) rep2(l, -10, 11)
                {
                    bool ok = true;
                    for (auto &p : bp)
                    {
                        int yi = p.first + k;
                        int xi = p.second + l;
                        if (0 <= yi && yi < hx && 0 <= xi && xi < wx && x[yi][xi] == '#')
                        {
                            xp_cp.erase({yi, xi});
                        }
                        else
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok && xp_cp.empty())
                    {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
}
