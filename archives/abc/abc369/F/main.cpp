#include <queue>

#include "hassaku/doubly-linked-list.hpp"
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#ifndef ONLINE_JUDGE
#define DEBUG 1
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll H, W, N;
    cin >> H >> W >> N;
    vl R(N), C(N);  // コインの座標
    rep(i, N) {
        cin >> R[i] >> C[i];
        R[i]--, C[i]--;
    }
    vpll RC(N);  // コインの座標
    rep(i, N) RC[i] = {R[i], C[i]};
    map<pll, ll> mp;
    rep(i, N) mp[RC[i]] = i;
    mp[{0, 0}] = N;
    mp[{H - 1, W - 1}] = N + 1;

    hassaku::DoublyLinkedList dll;

    dll.push_back(N);
    dll.push_back(N + 1);

    set<pll> max_path;
    max_path.emplace(0, 0);
    max_path.emplace(H - 1, W - 1);

    RC.emplace_back(0, 0);
    RC.emplace_back(H - 1, W - 1);

    rep(i, N) {
        auto [r, c] = RC[i];
        auto it = max_path.lower_bound({r, c});
        auto [ar, ac] = *it;
        int idx = mp[{ar, ac}];
        auto node = dll.find(idx);
        auto prev_node = node->prev;
        int prev_idx = prev_node->key;
        auto [br, bc] = RC[prev_idx];
        if (br <= r && bc <= c && r <= ar && c <= ac) {
            dll.insert(prev_idx, mp[{r, c}]);
            max_path.emplace(r, c);
        }
    }

    cout << dll.size() - 2 << endl;

    string ans;
    auto node = dll.begin()->next;
    pll prev = {0, 0};
    while (node->next != nullptr) {
        auto [r, c] = RC[node->key];
        while (prev.first < r) {
            ans += 'D';
            prev.first++;
        }
        while (prev.first > r) {
            ans += 'U';
            prev.first--;
        }
        while (prev.second < c) {
            ans += 'R';
            prev.second++;
        }
        while (prev.second > c) {
            ans += 'L';
            prev.second--;
        }
        prev = {r, c};
        node = node->next;
    }
    cout << ans << endl;
}
