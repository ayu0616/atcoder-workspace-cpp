#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

template <class T>
void vector_in(vector<T> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        T x;
        cin >> x;
        v.push_back(x);
    }
}

class Graph
{
public:
    unordered_map<int, set<int>> edges;

    /* n: 枝の数
    directed: 有向グラフかどうか
     */
    Graph(int n, bool directed = false)
    {
        rep(_, n)
        {
            int u, v;
            cin >> u >> v;
            this->edges[u].insert(v);
            if (!directed)
            {
                this->edges[v].insert(u);
            }
        }
    }
};

template <class T>
void show_array(T arr[], ll n)
{
    rep(i, n)
    {
        cout << arr[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
}

template <class T>
void show_multi_array(T arr[], ll n, ll m)
{
    rep(i, n)
    {
        show_array(arr[i], m);
    }
}

vector<ll> create_primes(ll upper)
{
    vector<ll> primes;
    vector<bool> is_p(upper + 1, true);

    for (ll i = 2; i <= upper; i++)
    {
        if (is_p[i])
        {
            primes.push_back(i);
            for (ll j = i * 2; j <= upper; j += i)
            {
                is_p[j] = false;
            }
        }
    }
    return primes;
}

template <class T>
map<T, int> prime_factorize(T n)
{
    map<T, int> res;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1)
    {
        res[n] = 1;
    }
    return res;
}
#line 2 "abc234/E/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

set<ll> gen_tousa()
{
    set<ll> res;
    for (int digit = 1; digit <= 18; digit++)
    {
        for (int d = -9; d <= 9; d++)
        {
            for (int i = 0; i < 10; i++)
            {
                vector<int> tmp(digit, 0);
                bool ok = true;
                rep(j, digit)
                {
                    if (j == 0)
                    {
                        tmp[0] = i;
                    }
                    else
                    {
                        int x = tmp[j - 1] + d;
                        if (x < 0 || x > 9)
                        {
                            ok = false;
                            break;
                        }
                        tmp[j] = x;
                    }
                }
                if (ok && tmp.back() != 0)
                {
                    ll num = 0;
                    rep(j, digit) num += tmp[j] * (ll)pow(10, j);
                    // cout << num << endl;
                    res.insert(num);
                }
            }
        }
    }
    return res;
}

int main()
{
    ll x;
    cin >> x;
    auto tousa = gen_tousa();
    auto ans = *tousa.lower_bound(x);
    cout << ans << endl;
}
