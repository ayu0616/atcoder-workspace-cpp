#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    vector<int> balls;
    pair<int, int> seq = {0, 0};
    rep(i, n)
    {
        balls.push_back(a[i]);
        if (a[i] == seq.first)
        {
            seq.second++;
            if (seq.second == a[i])
            {
                rep(j, a[i]) balls.pop_back();
                seq = {balls.back(), 1};
                for (int j = balls.size() - 2; j >= 0; j--)
                {
                    if (balls[j] == seq.first)
                        seq.second++;
                    else
                        break;
                }
            }
        }
        else
        {
            seq.first = a[i];
            seq.second = 1;
        }
        cout << balls.size() << endl;
    }
}
