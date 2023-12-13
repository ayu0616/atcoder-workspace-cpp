#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

string zeros = "000000000000000";

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    sort(all(S));

    ll ans = 0, cur = 0;

    for (ll i = 0; i < sqrt(powl(10, N)); ++i)
    {
        cur += 2 * i + 1;
        string tmp = to_string(cur);
        sort(all(tmp));
        tmp = (zeros + tmp).substr(tmp.size() + zeros.size() - N);
        if (tmp == S)
            ans++;
    }

    cout << ans << endl;
}
