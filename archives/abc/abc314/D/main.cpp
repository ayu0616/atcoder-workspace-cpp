#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

bool is_upper(char c)
{
    return 'A' <= c && c <= 'Z';
}

char to_upper(char c)
{
    if (is_upper(c))
    {
        return c;
    }
    else
    {
        return c - 'a' + 'A';
    }
}

char to_lower(char c)
{
    if (is_upper(c))
    {
        return c - 'A' + 'a';
    }
    else
    {
        return c;
    }
}

int main()
{
    int n, q, t, x;
    char c;
    string s;
    cin >> n >> s >> q;
    bool now_upper = true;
    set<int> revs;
    rep(i, n)
    {
        if (!is_upper(s[i]))
        {
            revs.insert(i);
        }
    }
    rep(_, q)
    {
        cin >> t >> x >> c;
        x--;
        if (t == 1)
        {
            s[x] = c;
            if (is_upper(c) != now_upper)
            {
                revs.insert(x);
            }else if(revs.find(x)!=revs.end()){
                revs.erase(x);
            }
        }
        else if (t == 2)
        {
            now_upper = false;
            revs.clear();
        }
        else
        {
            now_upper = true;
            revs.clear();
        }
    }
    rep(i, n)
    {
        if (revs.find(i) != revs.end())
        {
            if (now_upper)
            {
                cout << to_lower(s[i]);
            }
            else
            {
                cout << to_upper(s[i]);
            }
        }
        else
        {
            if (now_upper)
            {
                cout << to_upper(s[i]);
            }
            else
            {
                cout << to_lower(s[i]);
            }
        }
    }
    cout << endl;
}
