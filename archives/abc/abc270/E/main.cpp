#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vl A(N);
    cin >> A;
    priority_queue<ll, vl, greater<ll>> pq;
    for (auto a : A) {
        pq.push(a);
    }
    ll cur = 0;     // 現在までに食べたりんごの数
    ll cycles = 0;  // 現在までの周回数
    ll rest = N;    // 1こ以上りんごが存在するかごの数
    while (cur < K) {
        ll next_cycle = pq.top() - cycles;
        ll next = cur + next_cycle * rest;
        if (next > K) {
            ll additional_cycles = (K - cur) / rest;
            cycles += additional_cycles;
            cur += additional_cycles * rest;
            break;
        }
        cycles += next_cycle;
        cur = next;
        const ll min = pq.top();
        while (pq.size() > 0 && pq.top() == min) {
            pq.pop();
            rest--;
        }
    }
    vl ans;
    for (auto a : A) {
        a -= cycles;
        chmax(a, 0LL);
        if (cur < K && a > 0) {
            cur++;
            a--;
        }
        ans.push_back(a);
    }
    cout << ans << endl;
}
