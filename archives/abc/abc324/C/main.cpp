#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

bool c2(string s, string t)
{
    if (s.size() != t.size() + 1)
        return false;
    bool f = false;
    rep(i, t.size())
    {
        if (f)
        {
            if (s[i] != t[i - 1])
                return false;
        }
        else
        {
            if (s[i] != t[i])
                f = true;
        }
    }
    if (f && s.back() != t.back())
        return false;
    return true;
}

bool c3(string s, string t)
{
    if (s.size() + 1 != t.size())
        return false;
    bool f = false;
    rep(i, s.size())
    {
        if (f)
        {
            if (s[i - 1] != t[i])
                return false;
        }
        else
        {
            if (s[i] != t[i])
                f = true;
        }
    }
    if (f && s.back() != t.back())
        return false;
    return true;
}

bool c4(string s, string t)
{
    if (s.size() != t.size())
        return false;
    bool f = false;
    rep(i, s.size())
    {
        if (f)
        {
            if (s[i] != t[i])
                return false;
        }
        else
        {
            if (s[i] != t[i])
                f = true;
        }
    }
    return true;
}

map<pair<string, string>, ll> memo;
ll ld(string s, string t, ll now = 0)
{
    if (now >= 5)
        return memo[{s, t}] = 5;
    if (memo.count({s, t}) > 0)
        return memo[{s, t}];
    if (s.empty())
        return memo[{s, t}] = t.size();
    if (t.empty())
        return memo[{s, t}] = s.size();
    ll res = ld(s.substr(1), t.substr(1)) + (s[0] != t[0]);
    res = min(res, ld(s.substr(1), t, res) + 1);
    res = min(res, ld(s, t.substr(1), res) + 1);
    return memo[{s, t}] = res;
}

int main()
{
    ll N;
    string T;
    cin >> N >> T;
    vector<string> S(N);
    rep(i, N) cin >> S[i];
    ll ans = 0;
    vl ans_arr;

    // set<string> tSet;

    // tSet.insert(T);
    // rep(i, T.size() + 1)
    // {
    //     for (char c = 'a'; c <= 'z'; c++)
    //     {
    //         tSet.insert(T.substr(0, i) + c + T.substr(i));
    //     }
    // }
    // rep(i, T.size())
    // {
    //     tSet.insert(T.substr(0, i) + T.substr(i + 1));
    //     for (char c = 'a'; c <= 'z'; c++)
    //     {
    //         tSet.insert(T.substr(0, i) + c + T.substr(i + 1));
    //     }
    // }

    rep(i, N)
    {
        // if (S[i] == T)
        // {
        //     ans++;
        //     ans_arr.push_back(i + 1);
        // }
        // else if (c2(S[i], T))
        // {
        //     ans++;
        //     ans_arr.push_back(i + 1);
        // }
        // else if (c3(S[i], T))
        // {
        //     ans++;
        //     ans_arr.push_back(i + 1);
        // }
        // else if (c4(S[i], T))
        // {
        //     ans++;
        //     ans_arr.push_back(i + 1);
        // }
        // if (tSet.count(S[i]) > 0)
        // {
        //     ans++;
        //     ans_arr.push_back(i + 1);
        // }
        if (ld(S[i], T) <= 1)
        {
            ans++;
            ans_arr.push_back(i + 1);
        }
    }
    cout << ans << endl;
    if (ans)
        cout << ans_arr << endl;
}
