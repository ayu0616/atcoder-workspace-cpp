#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int m;
    string S1, S2, S3;
    cin >> m >> S1 >> S2 >> S3;
    int ans = 1e9;
    rep(i, m)
    {
        rep2(j, 1, m + 1)
        {
            rep2(k, 1, m + 1)
            {
                if (S1[i] == S2[(i + j) % m] && S2[(i + j) % m] == S3[(i + j + k) % m])
                {
                    ans = min(ans, i + j + k);
                }
                else if (S2[i] == S1[(i + j) % m] && S1[(i + j) % m] == S3[(i + j + k) % m])
                {
                    ans = min(ans, i + j + k);
                }
                else if (S3[i] == S1[(i + j) % m] && S1[(i + j) % m] == S2[(i + j + k) % m])
                {
                    ans = min(ans, i + j + k);
                }
                else if (S1[i] == S3[(i + j) % m] && S3[(i + j) % m] == S2[(i + j + k) % m])
                {
                    ans = min(ans, i + j + k);
                }
                else if (S2[i] == S3[(i + j) % m] && S3[(i + j) % m] == S1[(i + j + k) % m])
                {
                    ans = min(ans, i + j + k);
                }
                else if (S3[i] == S2[(i + j) % m] && S2[(i + j) % m] == S1[(i + j + k) % m])
                {
                    ans = min(ans, i + j + k);
                }
            }
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
}
