#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)

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
#line 2 "arc145/A/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans = "Yes";
    if((s[0]=='A' && s[n-1]=='B')||s=="BA"){
        ans = "No";
    }
    cout << ans << endl;
}
