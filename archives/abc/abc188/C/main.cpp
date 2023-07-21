#if !__INCLUDE_LEVEL__
#include __FILE__

int n, m;

int main()
{
    cin >> n;
    vector<int> a, a_cp;
    rep(i, pow(2, n))
    {
        int x;
        cin >> x;
        a.push_back(x);
        a_cp.push_back(x);
    }
    rep(i, n - 1)
    {
        vector<int> b;
        rep(j, pow(2, n - i - 1))
        {
            b.push_back(max(a[2 * j], a[2 * j + 1]));
        }
        a = b;
    }
    int ans;
    int m = min(a[0], a[1]);
    rep(i, pow(2, n))
    {
        if (a_cp[i] == m)
        {
            ans = i + 1;
            break;
        }
    }
    cout << ans << endl;
}

#else

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#endif