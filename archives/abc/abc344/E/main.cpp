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
    int N, Q;
    cin >> N;
    vi A(N);
    cin >> A >> Q;
    hassaku::DoublyLinkedList list;
    for (int a : A) {
        list.push_back(a);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            list.insert(x, y);
        } else {
            int x;
            cin >> x;
            list.erase(x);
        }
    }
    list.print();
}
