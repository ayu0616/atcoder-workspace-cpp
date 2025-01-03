#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Item {
    ll id;
    ll value;
};

bool operator<(const Item &lhs, const Item &rhs) { return lhs.id < rhs.id; }

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vl A(N);
    cin >> A;

    vector<Item> s;
    vector<vector<Item>> v(M);
    rep(i, N) {
        if (A[i] >= 0) {
            s.emplace_back(i + 1, A[i]);
        } else {
            ll k = (-A[i]) / (i + 1);
            Item item = {i + 1, A[i] + k * (i + 1)};
            if (item.value >= 0 && k - 1 < M) {
                v[k - 1].push_back(item);
            } else if (k < M) {
                item.value += i + 1;
                v[k].push_back(item);
            }
        }
    }
    // rep(i, M) {
    //     cerr << "v[" << i << "]: ";
    //     for (auto &item : v[i]) {
    //         cerr << item.id << ": " << item.value << ", ";
    //     }
    //     cerr << endl;
    // }

    rep(i, M) {
        vector<Item> ns;
        set<ll> values;
        for (auto &item : s) {
            ll nv = item.value + item.id;
            if (nv > N) {
                continue;
            }
            ns.emplace_back(item.id, nv);
            values.insert(nv);
        }
        s = ns;
        for (auto &item : v[i]) {
            s.emplace_back(item.id, item.value);
            values.insert(item.value);
        }
        if (s.empty()) {
            cout << 0 << endl;
            continue;
        }
        rep(i, s.size()+1) {
            if (values.count(i) == 0) {
                cout << i << endl;
                break;
            }
        }
    }
}
