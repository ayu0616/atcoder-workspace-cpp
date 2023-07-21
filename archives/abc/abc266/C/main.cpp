#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int nodes[4][2];
string ans;
int i, j, k;
double s, co;
int ab[2], ad[2];

const double EPS = 1e-9;

double vec_abs(int vec[2])
{
    return sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
}

int vec_dot(int vec1[2], int vec2[2])
{
    return vec1[0] * vec2[0] + vec1[1] * vec2[1];
}

int main()
{
    rep(i, 4)
    {
        cin >> nodes[i][0] >> nodes[i][1];
    }
    ans = "Yes";
    s = 0.0;

    rep(i, 4)
    {
        j = (i + 1);
        k = (i - 1);
        if (j > 3)
            j -= 4;
        if (k < 0)
            k += 4;
        // cout << i << " " << j << " " << k << endl;
        rep(l, 2)
        {
            ab[l] = nodes[j][l] - nodes[i][l];
            ad[l] = nodes[k][l] - nodes[i][l];
        }
        // cout << vec_dot(ab, ad) << " " << vec_abs(ab) << " " << vec_abs(ad) << endl;
        co = vec_dot(ab, ad) / (vec_abs(ab) * vec_abs(ad));
        s += acos(co);
    }
    if (2 * M_PI - s < EPS)
    {
        ans = "Yes";
    }
    else
    {
        ans = "No";
    }
    cout << ans << endl;
}
