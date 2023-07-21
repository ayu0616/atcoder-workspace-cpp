#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using heap = priority_queue<int, vector<int>, greater<int>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (a); i < (int)(b); i++)

/* グラフ（mapを継承） */
template <class T>
class Graph : public unordered_map<T, set<T>>
{
};

/* 素数判定 */
bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

/* 素数生成 */
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

/* 素因数分解 */
template <class T>
vl prime_factorize(T n)
{
    vl res;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res.emplace_back(i);
            n /= i;
        }
    }
    if (n != 1)
    {
        res.emplace_back(n);
    }
    return res;
}

template <class T>
class UnionFind
{
    vector<T> par, rank, siz;

public:
    // n: 頂点数
    UnionFind(T n)
    {
        par = vector<T>(n, -1);
        rank = vector<T>(n, 0);
        siz = vector<T>(n, 1);
    }

    // xの根を求める
    T root(T x)
    {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    // xとyが同じグループに属するかどうか（根が一致するかどうか）
    bool same(T x, T y)
    {
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループとを併合する
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

    // xを含むグループのサイズ
    T size(T x)
    {
        return siz[root(x)];
    }

    // グループ数
    T groups()
    {
        T res = 0;
        for (T i = 0; i < par.size(); i++)
        {
            if (par[i] == -1)
                res++;
        }
        return res;
    }
};

/*
自動的にmodを取ってくれる型
使い方：static_modint<mod> a;
ただし、modは素数でなければならない
*/
template <int mod>
class static_modint
{
    ll x;

public:
    static_modint(ll x = 0) : x((x % mod + mod) % mod) {}
    static_modint operator-() const
    {
        return static_modint(-x);
    }
    static_modint &operator+=(const static_modint &a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    static_modint &operator-=(const static_modint &a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    static_modint &operator*=(const static_modint &a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    static_modint operator+(const static_modint &a) const
    {
        static_modint res(*this);
        return res += a;
    }
    static_modint operator-(const static_modint &a) const
    {
        static_modint res(*this);
        return res -= a;
    }
    static_modint operator*(const static_modint &a) const
    {
        static_modint res(*this);
        return res *= a;
    }
    // 二分累乗法によるべき乗
    static_modint pow(ll t) const
    {
        if (!t)
            return 1;
        static_modint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }
    // 逆元を求める
    static_modint inv() const
    {
        return pow(mod - 2);
    }
    static_modint &operator/=(const static_modint &a)
    {
        return (*this) *= a.inv();
    }
    static_modint operator/(const static_modint &a) const
    {
        static_modint res(*this);
        return res /= a;
    }

    friend ostream &operator<<(ostream &os, const static_modint &m)
    {
        os << m.x;
        return os;
    }
};

// 桁和
template <class T>
int digit_sum(T n)
{
    int res = 0;
    while (n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << endl;
    }
    return os;
}
#line 2 "arc160/A/main.cpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi b(n);
    int cnt = 0;

    rep(i, n)
    {
        vi sm, lg;
        rep(j, a.size())
        {
            if (a[0] > a[j])
            {
                sm.push_back(a[j]);
            }
            if (a[0] < a[j])
            {
                lg.push_back(a[j]);
            }
        }
        int eq = a.size() * (a.size() + 1) / 2 - sm.size() - lg.size();
        if (k <= cnt + sm.size())
        {
            sort(sm.begin(), sm.end());
            int sm_i = k - cnt;
            vi::iterator a_sm_i = find(a.begin(), a.end(), sm[sm_i - 1]);
            reverse(a.begin(),  a_sm_i);
            rep(j, a.size()) b[i + j] = a[j];
            break;
        }
        else if (k <= cnt + sm.size() + eq)
        {
            b[i] = a[0];
            a.erase(a.begin());
            cnt += sm.size();
        }
        else
        {
            sort(lg.begin(), lg.end());
            int lg_i = k - cnt - sm.size() - eq;
            vi::iterator a_lg_i = find(a.begin(), a.end(), lg[lg_i - 1]);
            reverse(a.begin(),  a_lg_i);
            rep(j, a.size()) b[i + j] = a[j];
            break;
        }
    }
    cout << b << endl;

    // vvi revs;
    // rep(i, n) rep2(j, i, n)
    // {
    //     if (i == j)
    //     {
    //         revs.push_back(a);
    //     }
    //     else
    //     {
    //         vi tmp = revs.back();
    //         vi rev(n);
    //         rep(l, i) { rev[l] = tmp[l]; }
    //         rev[i] = tmp[j];
    //         rep(l, j - i)
    //         {
    //             rev[l + i + 1] = tmp[l + i];
    //         }
    //         rep2(l, j - i + 1, n)
    //         {
    //             rev[l] = tmp[l];
    //         }
    //         revs.push_back(rev);
    //     }
    // }

    // sort(revs.begin(), revs.end());
    // cout << revs[k - 1] << endl;
}
