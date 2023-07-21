#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int n;
vector<int> q, a;

int main()
{
    cin >> n;
    pair<int, int> range{1, n};
    int n1;
    for (int i = 0; i < 20; i++)
    {
        if (range.first + 1 == range.second)
        {
            break;
        }
        if (i > 1)
        {
            if (a.back() == 0)
                range.first = n1;
            else
                range.second = n1;
        }
        n1 = (range.first + range.second) / 2;
        cout << "? " << n1 << endl;
        int ans;
        cin >> ans;
        q.push_back(n1);
        a.push_back(ans);
    }
    cout << "! " << range.first << endl;
}
