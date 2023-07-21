#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vi a(n);
    vector<deque<int>> q(5);
    rep(i, n)
    {
        cin >> a[i];
        q[a[i]].push_back(i);
    }
    vi b = a;
    sort(b.begin(), b.end());
    vi diff(n, 0);
    rep(i, n)
    {
        int idx = q[a[i]].front();
        diff[i] = i - idx;
        b[idx] = 0;
    }
    int cnt_p = 0, cnt_m = 0;
    rep(i, n)
    {
        if (diff[i] > 0)
        {
            cnt_p++;
        }
        else if (diff[i] < 0)
        {
            cnt_m++;
        }
    }
    cout << max(cnt_p, cnt_m) << endl;
}
