#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

template <class T>
class Graph : public unordered_map<T, set<T>>
{
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

template <class T>
class UnionFind
{
    vector<T> par, rank, siz;

public:
    UnionFind(T n)
    {
        par = vector<T>(n, -1);
        rank = vector<T>(n, 0);
        siz = vector<T>(n, 1);
    }

    T root(T x)
    {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool same(T x, T y)
    {
        return root(x) == root(y);
    }

    void unite(T x, T y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;

        if (rank[x] < rank[y])
            swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
        siz[x] += siz[y];
    }

    T size(T x)
    {
        return siz[root(x)];
    }
};
#line 2 "abc278/E/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int H, W, n, h, w;
    cin >> H >> W >> n >> h >> w;
    vector<vector<int>> A(H, vector<int>(W));
    vector<int> mp(n + 1, 0);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
        {
            int a;
            cin >> a;
            if (i >= h || j >= w)
                mp[a]++;
            A[i][j] = a;
        }

    vector<vector<vector<int>>> ans(H - h + 1, vector<vector<int>>(W - w + 1, vector<int>(n + 1, 0)));
    ans[0][0] = mp;
    // for (int i = 0; i < h; i++)
    //     for (int j = 0; j < w; j++)
    //     {
    //         ans[0][0][A[i][j]]--;
    //     }

    int cnt = 0;
    for (int t = 1; t <= n; t++)
    {
        if (ans[0][0][t] > 0)
            cnt++;
    }
    int tmp = cnt;
    for (int k = 0; k < H - h + 1; k++)
    {
        if (k >= 1)
        {
            cnt = tmp;
            ans[k][0] = ans[k - 1][0];
            for (int i = 0; i < w; i++)
            {
                ans[k][0][A[k - 1][i]]++;
                if (ans[k][0][A[k - 1][i]] == 1)
                    cnt++;
                ans[k][0][A[k + h - 1][i]]--;
                if (ans[k][0][A[k + h - 1][i]] == 0)
                    cnt--;
            }
        }
        tmp = cnt;
        cout << cnt << " ";
        for (int l = 1; l < W - w + 1; l++)
        {
            ans[k][l] = ans[k][l - 1];
            for (int i = 0; i < h; i++)
            {
                ans[k][l][A[k + i][l - 1]]++;
                if (ans[k][l][A[k + i][l - 1]] == 1)
                    cnt++;
                ans[k][l][A[k + i][l + w - 1]]--;
                if (ans[k][l][A[k + i][l + w - 1]] == 0)
                    cnt--;
            }
            cout << cnt << " \n"[l == W - w];
        }
    }
    // for (int i = 0; i < H - h + 1; i++)
    // {
    //     for (int j = 0; j < W - w + 1; j++)
    //     {
    //         cnt = 0;
    //         for (int k = 1; k <= n; k++)
    //         {
    //             if (ans[i][j][k] > 0)
    //                 cnt++;
    //         }
    //         cout << cnt << " \n"[j == W - w];
    //     }
    // }
}
