#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    deque<char> s;
    string t;
    cin >> t;
    for (int i = 0; i < n; i++)
    {
        s.push_back(t[i]);
    }
    char c;
    c = s.front();
    s.pop_front();
    string ans = "Yes";
    while (s.size() > 0)
    {
        if (s.front() == c)
        {
            ans = "No";
            break;
        }
        else
        {
            c = s.front();
            s.pop_front();
        }
    }
    cout << ans << endl;
}
