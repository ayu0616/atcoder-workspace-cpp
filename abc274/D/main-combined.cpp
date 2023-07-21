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

template <class T>
map<T, int> prime_factorize(T n){
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
#line 2 "abc274/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ax, ay;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (i % 2 == 0)
            ax.push_back(a);
        else
            ay.push_back(a);
    }
    vector<bool> dpx(20001, false), dpy(20001, false);
    dpx[10000] = true;
    dpx[10000 + ax[0]] = true;
    ax = vector<int>(ax.begin() + 1, ax.end());
    rep(i, ax.size())
    {
        vector<bool> nxtdp(20001, false);
        rep(j, 20001)
        {
            if (dpx[j])
            {
                if (j + ax[i] <= 20000)
                    nxtdp[j + ax[i]] = true;
                if (j - ax[i] >= 0)
                    nxtdp[j - ax[i]] = true;
            }
        }
        dpx = nxtdp;
    }
    dpy[10000] = true;
    rep(i, ay.size())
    {
        vector<bool> nxtdp(20001, false);
        rep(j, 20001)
        {
            if (dpy[j])
            {
                if (j + ay[i] <= 20000)
                    nxtdp[j + ay[i]] = true;
                if (j - ay[i] >= 0)
                    nxtdp[j - ay[i]] = true;
            }
        }
        dpy = nxtdp;
    }
    bool ans = dpx[10000 + x] && dpy[10000 + y];
    cout << (ans ? "Yes" : "No") << endl;
}
