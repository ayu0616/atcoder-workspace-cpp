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
#line 2 "abc301/D/main.cpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll ans, n;
// void solve(vi &a, int i, ll cnt)
// {
//     if (i >= a.size())
//         return;
//     ll two_a = powl(2, a[i]);
//     ll bigger = cnt + two_a;
//     if (!(ans > cnt + two_a - 1))
//     {
//         solve(a, i + 1, cnt);
//     }
//     if (!(bigger > n))
//     {
//         ans = max(ans, bigger);
//         solve(a, i + 1, bigger);
//     }
// }

int main()
{
    string s;
    cin >> s;
    cin >> n;
    // bitset<64> bs(n);
    // string bin = bs.to_string();

    vi question;

    ans = 0;
    rep(i, s.size())
    {
        if (s[i] == '1')
        {
            ans += powl(2, s.size() - i - 1);
        }
        else if (s[i] == '?')
        {
            question.push_back(s.size() - i - 1);
        }
    }
    if (ans > n)
    {
        cout << -1 << endl;
        return 0;
    }
    sort(question.begin(), question.end());
    reverse(question.begin(), question.end());
    // solve(question, 0, ans);
    rep(i, question.size())
    {
        ll two_a = powl(2, question[i]);
        ll bigger = ans + two_a;
        if (bigger <= n)
        {
            ans = bigger;
        }
    }
    cout << ans << endl;
}
