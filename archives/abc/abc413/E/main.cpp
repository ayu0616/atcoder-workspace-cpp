#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
struct Node {
    T value;
    Node *l, *r;
    int size;
    uint32_t prio;
    bool rev;

    Node(T v) : value(v), l(nullptr), r(nullptr), size(1), prio(rng()), rev(false) {}
};

template <typename T>
class ImplicitTreap {
   private:
    using NodePtr = Node<T>*;
    NodePtr root = nullptr;

    int size(NodePtr t) { return t ? t->size : 0; }

    void update_size(NodePtr t) {
        if (t) t->size = size(t->l) + size(t->r) + 1;
    }

    void push(NodePtr t) {
        if (t && t->rev) {
            std::swap(t->l, t->r);
            if (t->l) t->l->rev ^= 1;
            if (t->r) t->r->rev ^= 1;
            t->rev = false;
        }
    }

    void split(NodePtr t, int k, NodePtr& l, NodePtr& r) {
        if (!t) {
            l = r = nullptr;
            return;
        }
        push(t);
        int left_size = size(t->l);
        if (k <= left_size) {
            split(t->l, k, l, t->l);
            r = t;
        } else {
            split(t->r, k - left_size - 1, t->r, r);
            l = t;
        }
        update_size(t);
    }

    NodePtr merge(NodePtr l, NodePtr r) {
        push(l);
        push(r);
        if (!l || !r) return l ? l : r;

        if (l->prio > r->prio) {
            l->r = merge(l->r, r);
            update_size(l);
            return l;
        } else {
            r->l = merge(l, r->l);
            update_size(r);
            return r;
        }
    }

    void to_vector_internal(NodePtr t, std::vector<T>& vec) {
        if (!t) return;
        push(t);
        to_vector_internal(t->l, vec);
        vec.push_back(t->value);
        to_vector_internal(t->r, vec);
    }

   public:
    ImplicitTreap() = default;

    ImplicitTreap(const std::vector<T>& initial_values) {
        rep(i, initial_values.size()) { insert(i, initial_values[i]); }
    }

    void insert(int k, T v) {
        NodePtr l, r;
        split(root, k, l, r);
        root = merge(merge(l, new Node<T>(v)), r);
    }

    void erase(int k) {
        NodePtr l, m, r;
        split(root, k, l, r);
        split(r, 1, m, r);

        root = merge(l, r);
    }

    void reverse(int l, int r) {
        if (l >= r) return;
        NodePtr t1, t2, t3;
        split(root, r, t1, t3);
        split(t1, l, t1, t2);

        if (t2) t2->rev ^= 1;

        root = merge(merge(t1, t2), t3);
    }

    void cyclic_shift(int l, int r, int k) {
        if (l >= r) return;
        int len = r - l;
        k %= len;
        if (k < 0) k += len;
        if (k == 0) return;

        NodePtr t1, t2, t3, t4;
        split(root, r, t1, t4);
        split(t1, l, t1, t2);
        split(t2, len - k, t2, t3);

        root = merge(merge(merge(t1, t3), t2), t4);
    }

    T get(int k) {
        NodePtr t = root;
        while (t) {
            push(t);
            int left_size = size(t->l);
            if (k < left_size) {
                t = t->l;
            } else if (k == left_size) {
                return t->value;
            } else {
                t = t->r;
                k -= left_size + 1;
            }
        }
        return T();
    }

    int get_size() { return size(root); }

    std::vector<T> to_vector() {
        std::vector<T> vec;
        to_vector_internal(root, vec);
        return vec;
    }
};

int main() {
    cout << fixed << setprecision(18);
    ll T;
    cin >> T;
    rep(T) {
        ll N;
        cin >> N;
        vl P(1LL << N);
        cin >> P;
        ImplicitTreap<ll> treap(P);
        rep(_, N) {
            rep(i, 1ll << N) {
                ll a = i, b = 0;
                ll min = treap.get(i);
                ll min_index = i;
                while ((a + 1) * (1ll << b) <= (1ll << N)) {
                    assert(a * (1ll << b) == i);
                    ll c = (a + 1) * (1ll << b) - 1;
                    ll v = treap.get(c);
                    if (v < min) {
                        min = v;
                        min_index = c;
                    }
                    if (a % 2 != 0) {
                        break;
                    }
                    a /= 2;
                    b++;
                }
                treap.reverse(i, min_index + 1);
            }
        }
        cout << treap.to_vector() << endl;
    }
}
