#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int h, w;
vector<string> s;

int main()
{
    cin >> h >> w;
    s.resize(h);
    rep(i, h) cin >> s[i];
    rep(i, h) s[i] = regex_replace(s[i], regex("TT"), "PC");
    rep(i, h) cout << s[i] << endl;
}
