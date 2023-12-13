#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N;
    cin >> N;
    vl T(N), D(N);
    vector<bool> done(N, false);
    rep(i, N) cin >> T[i] >> D[i];
    set<ll> times;
    rep(i, N)
    {
        times.insert(T[i]);
        times.insert(T[i] + D[i]);
    }
    map<ll, vector<ll>> in_events, out_events;
    rep(i, N)
    {
        in_events[T[i]].push_back(i);
        out_events[T[i] + D[i]].push_back(i);
    }
    ll ans = 0;
    ll prev_time = *times.begin() - 1;
    greater_heap<ll> q;
    for (auto time : times)
    {
        ll cnt = time - prev_time;
        while (!q.empty() && cnt > 1)
        {
            q.pop();
            cnt--;
            ans++;
        }
        for (auto i : in_events[time])
        {
            q.push(time + D[i]);
        }
        if (!q.empty())
        {
            ans++;
            q.pop();
        }
        while (!q.empty() && time >= q.top())
            q.pop();
        prev_time = time;
    }
    cout << ans << endl;
}
