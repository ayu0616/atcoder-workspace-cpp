#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) { cin >> s[i]; }
    string snuke = "snuke";
    rep(i, h) rep(j, w - 4)
    {
        string ans1 = s[i].substr(j, 5);
        string ans2 = s[i].substr(j, 5);
        reverse(ans2.begin(), ans2.end());
        if (ans1 == snuke)
        {
            rep(k, 5)
            {
                cout << i + 1 << " " << j + k + 1 << endl;
            }
        }
        if (ans2 == snuke)
        {
            rep(k, 5)
            {
                cout << i + 1 << " " << j + 4 - k + 1 << endl;
            }
        }
    }

    rep(j, w) rep(i, h - 4)
    {
        string ans1 = "";
        string ans2 = "";
        rep(k, 5)
        {
            ans1 += s[i + k][j];
            ans2 += s[i + 4 - k][j];
        }
        if (ans1 == snuke)
        {
            rep(k, 5)
            {
                cout << i + k + 1 << " " << j + 1 << endl;
            }
        }
        if (ans2 == snuke)
        {
            rep(k, 5)
            {
                cout << i + 4 - k + 1 << " " << j + 1 << endl;
            }
        }
    }

    rep(i, h - 4) rep(j, w - 4)
    {
        string ans1 = "";
        string ans2 = "";
        rep(k, 5)
        {
            ans1 += s[i + k][j + k];
            ans2 += s[i + 4 - k][j + 4 - k];
        }
        if (ans1 == snuke)
        {
            rep(k, 5)
            {
                cout << i + k + 1 << " " << j + k + 1 << endl;
            }
        }
        if (ans2 == snuke)
        {
            rep(k, 5)
            {
                cout << i + 4 - k + 1 << " " << j + 4 - k + 1 << endl;
            }
        }
    }

    rep(i, h - 4) rep(j, w - 4)
    {
        string ans1 = "";
        string ans2 = "";
        rep(k, 5)
        {
            ans1 += s[i + k][j + 4 - k];
            ans2 += s[i + 4 - k][j + k];
        }
        if (ans1 == snuke)
        {
            rep(k, 5)
            {
                cout << i + k + 1 << " " << j + 4 - k + 1 << endl;
            }
        }
        if (ans2 == snuke)
        {
            rep(k, 5)
            {
                cout << i + 4 - k + 1 << " " << j + k + 1 << endl;
            }
        }
    }

    // rep(i, h)
    // {
    //     rep(j, w - 4)
    //     {
    //         if (s[i][j] == 's' && s[i][j + 1] == 'n' && s[i][j + 2] == 'u' && s[i][j + 3] == 'k' && s[i][j + 4] == 'e')
    //         {
    //             rep(k, 5)
    //             {
    //                 cout << i + 1 << " " << j + k + 1 << endl;
    //             }
    //             return 0;
    //         }
    //         if (s[i][j] == 'e' && s[i][j + 1] == 'k' && s[i][j + 2] == 'u' && s[i][j + 3] == 'n' && s[i][j + 4] == 's')
    //         {
    //             rep(k, 5)
    //             {
    //                 cout << i + 1 << " " << j + 4 - k + 1 << endl;
    //             }
    //             return 0;
    //         }
    //     }
    // }

    // rep(j, w)
    // {
    //     rep(i, h - 4)
    //     {
    //         if (s[i][j] == 's' && s[i + 1][j] == 'n' && s[i + 2][j] == 'u' && s[i + 3][j] == 'k' && s[i + 4][j] == 'e')
    //         {
    //             rep(k, 5)
    //             {
    //                 cout << i + k + 1 << " " << j + 1 << endl;
    //             }
    //             return 0;
    //         }
    //         if (s[i][j] == 'e' && s[i + 1][j] == 'k' && s[i + 2][j] == 'u' && s[i + 3][j] == 'n' && s[i + 4][j] == 's')
    //         {
    //             rep(k, 5)
    //             {
    //                 cout << i + 4 - k + 1 << " " << j + 1 << endl;
    //             }
    //             return 0;
    //         }
    //     }
    // }

    // rep(i, h - 4)
    // {
    //     rep(j, w - 4)
    //     {
    //         if (s[i][j] == 's' && s[i + 1][j + 1] == 'n' && s[i + 2][j + 2] == 'u' && s[i + 3][j + 3] == 'k' && s[i + 4][j + 4] == 'e')
    //         {
    //             rep(k, 5)
    //             {
    //                 cout << i + k + 1 << " " << j + k + 1 << endl;
    //             }
    //             return 0;
    //         }
    //         if (s[i][j] == 'e' && s[i + 1][j + 1] == 'k' && s[i + 2][j + 2] == 'u' && s[i + 3][j + 3] == 'n' && s[i + 4][j + 4] == 's')
    //         {
    //             rep(k, 5)
    //             {
    //                 cout << i + 4 - k + 1 << " " << j + 4 - k + 1 << endl;
    //             }
    //             return 0;
    //         }
    //     }
    // }
}
