#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<deque<int>> A(M);
    vvi pos(N);
    rep(i, M)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int a;
            cin >> a;
            a--;
            A[i].push_back(a);
            pos[a].push_back(i);
        }
    }

    vi heads(N, 0);
    rep(i, M)
    {
        heads[A[i].front()]++;
    }
    set<pii> s;
    rep(i, N)
    {
        s.insert({heads[i], i});
    }

    set<int> used;
    pii max_elem;
    while (!s.empty() && (max_elem = *s.rbegin()).first == 2 && used.size() < N)
    {
        auto [_, i] = max_elem;
        s.erase(max_elem);
        if (used.count(i))
            continue;
        used.insert(i);
        for (auto j : pos[i])
        {
            heads[A[j].front()]--;
            A[j].pop_front();
            heads[A[j].front()]++;
            s.insert({heads[A[j].front()], A[j].front()});
        }
    }
    cout << (used.size() == N ? "Yes" : "No") << endl;
}
