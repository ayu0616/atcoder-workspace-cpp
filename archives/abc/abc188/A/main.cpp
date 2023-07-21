#if !__INCLUDE_LEVEL__
#include __FILE__

int n, m;

int main()
{
    // cin >> n;
    cin >> n >> m;
    if (abs(n - m) <= 2)
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
