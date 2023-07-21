#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int H, W, n, h, w;
    cin >> H >> W >> n >> h >> w;
    vector<vector<int>> A(H, vector<int>(W));
    vector<int> mp(n + 1, 0);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            int a;
            cin >> a;
            if (i >= h || j >= w)
                mp[a]++;
            A[i][j] = a;
        }

    vector<vector<vector<int>>> ans(H - h + 1, vector<vector<int>>(W - w + 1, vector<int>(n + 1, 0)));
    ans[0][0] = mp;
    // for (int i = 0; i < h; i++)
    //     for (int j = 0; j < w; j++)
    //     {
    //         ans[0][0][A[i][j]]--;
    //     }

    int cnt = 0;
    for (int t = 1; t <= n; t++)
    {
        if (ans[0][0][t] > 0)
            cnt++;
    }
    int tmp = cnt;
    for (int k = 0; k < H - h + 1; k++)
    {
        if (k >= 1)
        {
            cnt = tmp;
            ans[k][0] = ans[k - 1][0];
            for (int i = 0; i < w; i++)
            {
                ans[k][0][A[k - 1][i]]++;
                if (ans[k][0][A[k - 1][i]] == 1)
                    cnt++;
                ans[k][0][A[k + h - 1][i]]--;
                if (ans[k][0][A[k + h - 1][i]] == 0)
                    cnt--;
            }
        }
        tmp = cnt;
        cout << cnt << " ";
        for (int l = 1; l < W - w + 1; l++)
        {
            ans[k][l] = ans[k][l - 1];
            for (int i = 0; i < h; i++)
            {
                ans[k][l][A[k + i][l - 1]]++;
                if (ans[k][l][A[k + i][l - 1]] == 1)
                    cnt++;
                ans[k][l][A[k + i][l + w - 1]]--;
                if (ans[k][l][A[k + i][l + w - 1]] == 0)
                    cnt--;
            }
            cout << cnt << " \n"[l == W - w];
        }
    }
    // for (int i = 0; i < H - h + 1; i++)
    // {
    //     for (int j = 0; j < W - w + 1; j++)
    //     {
    //         cnt = 0;
    //         for (int k = 1; k <= n; k++)
    //         {
    //             if (ans[i][j][k] > 0)
    //                 cnt++;
    //         }
    //         cout << cnt << " \n"[j == W - w];
    //     }
    // }
}
