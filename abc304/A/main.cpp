#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    vl a(n);
    rep(i, n) cin >> s[i] >> a[i];

    ll min_a = *min_element(a.begin(), a.end());
    int min_index = find(a.begin(), a.end(), min_a) - a.begin();

    for (int i = 0; i < n; i++)
    {
        cout << s[(i+min_index) % n] << endl;
    }
}
