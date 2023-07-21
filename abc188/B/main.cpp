#if !__INCLUDE_LEVEL__
#include __FILE__

int n, m;

int main()
{
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += a[i] * b[i];
    }

    if (ans == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}

#else

#include <bits/stdc++.h>
using namespace std;

#endif
