#include "hassaku/doubly-linked-list.hpp"
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
    ll N, Q;
    cin >> N >> Q;
    vector<hassaku::LinkedListNode *> nodes(N);
    for (int i = 0; i < N; i++) {
        nodes[i] = new hassaku::LinkedListNode(i);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            hassaku::LinkedListNode *x_node = nodes[x], *y_node = nodes[y];
            x_node->next = y_node;
            y_node->prev = x_node;
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            hassaku::LinkedListNode *x_node = nodes[x], *y_node = nodes[y];
            x_node->next = nullptr;
            y_node->prev = nullptr;
        } else if (t == 3) {
            int x;
            cin >> x;
            x--;
            hassaku::LinkedListNode *cur = nodes[x];
            while (cur->prev != nullptr) {
                cur = cur->prev;
            }
            vi ans;
            while (cur != nullptr) {
                ans.push_back(cur->key + 1);
                cur = cur->next;
            }
            cout << ans.size() << " " << ans << endl;
        }
    }
}
