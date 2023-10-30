#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for (int i = (l); i < (r); i++)
#define bit(x, i) (((x) >> (i)) & 1)

long long solve(vector<int> &a, int s)
{
    int n = a.size();
    unordered_map<int, int> memo;
    rep(i, 0, 1 << (n / 2))
    {
        int t = 0;
        rep(k, 0, n / 2) t += bit(i, k) ? a[k] : -a[k];
        memo[t] = i;
    }
    rep(i, 0, 1 << (n - n / 2))
    {
        int t = 0;
        rep(k, 0, n - n / 2) t += bit(i, k) ? a[k + n / 2] : -a[k + n / 2];
        if (memo.find(s - t) != memo.end())
        {
            return (long long)i << (n / 2) | memo[s - t];
        }
    }
    return -1;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (i % 2)
            a.push_back(t);
        else
            b.push_back(t);
    }

    // 1が正、0が負
    auto retx = solve(a, x);
    auto rety = solve(b, y);
    if (retx == -1 || rety == -1)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

    // 0がx軸正、1がy軸正、2がx軸負、3がy軸負
    int dir = 0;
    string ans;
    for (int i = 0; i < n; i++)
    {
        int new_dir;
        if (i % 2)
            new_dir = 2 - 2 * bit(retx, i / 2);
        else
            new_dir = 3 - 2 * bit(rety, i / 2);
        if ((dir + 1) % 4 == new_dir)
            ans += 'L';
        else
            ans += 'R';
        dir = new_dir;
    }
    cout << ans << endl;
}
