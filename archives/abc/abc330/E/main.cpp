#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct nekoset
{
private:
    std::set<std::pair<int, int>> s;

public:
    nekoset()
    {
        s.emplace(INT_MIN, INT_MIN);
        s.emplace(INT_MAX, INT_MAX);
    }

    bool contains(int x) const
    {
        auto it = std::prev(s.lower_bound(std::make_pair(x + 1, x + 1)));
        auto [l, u] = *it;
        return l <= x && x <= u;
    }

    bool insert(int x)
    {
        auto nit = s.lower_bound(std::make_pair(x + 1, x + 1));
        auto it = std::prev(nit);
        auto [l, u] = *it;
        auto [nl, nu] = *nit;
        if (l <= x && x <= u)
            return false;
        if (u == x - 1)
        {
            if (nl == x + 1)
            {
                s.erase(it);
                s.erase(nit);
                s.emplace(l, nu);
            }
            else
            {
                s.erase(it);
                s.emplace(l, x);
            }
        }
        else
        {
            if (nl == x + 1)
            {
                s.erase(nit);
                s.emplace(x, nu);
            }
            else
            {
                s.emplace(x, x);
            }
        }
        return true;
    }

    bool erase(int x)
    {
        auto it = std::prev(s.lower_bound(std::make_pair(x + 1, x + 1)));
        auto [l, u] = *it;
        if (l <= x && x <= u)
        {
            s.erase(it);
            if (l <= x - 1)
            {
                if (x + 1 <= u)
                {
                    s.emplace(l, x - 1);
                    s.emplace(x + 1, u);
                }
                else
                {
                    s.emplace(l, x - 1);
                }
            }
            else
            {
                if (x + 1 <= u)
                {
                    s.emplace(x + 1, u);
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    int mex(int x = 0) const
    {
        auto [l, u] = *std::prev(s.lower_bound(std::make_pair(x + 1, x + 1)));
        if (l <= x && x <= u)
        {
            return u + 1;
        }
        else
        {
            return x;
        }
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    vl A(N);
    cin >> A;
    multiset<ll> ms;
    rep(i, N) ms.insert(A[i]);
    nekoset s;
    rep(i, N) s.insert(A[i]);

    ll i, x;
    while (Q--)
    {
        cin >> i >> x;
        i--;
        ll ai = A[i];
        ms.erase(ms.find(ai));
        ms.insert(x);
        if (ms.find(ai) == ms.end())
        {
            s.erase(A[i]);
        }
        s.insert(x);
        A[i] = x;
        cout << s.mex() << endl;
    }
}
