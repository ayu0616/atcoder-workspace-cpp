#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Dish {
    int id;
    int cnt;
    Dish(int id, int cnt) : id(id), cnt(cnt) {}
};

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vvi A(M);
    rep(i, M) {
        int k;
        cin >> k;
        A[i].resize(k);
        rep(j, k) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    vector<Dish*> dish_pointers(M);
    vector<vector<Dish*>> dishes(N);
    rep(i, M) {
        int k = A[i].size();
        dish_pointers[i] = new Dish(i, k);
    }
    rep(i, M) {
        for (auto a : A[i]) {
            dishes[a].push_back(dish_pointers[i]);
        }
    }
    vi B(N);
    cin >> B;
    rep(i, N) { B[i]--; }

    int ans = 0;
    rep(i, N) {
        int b = B[i];
        for (auto d : dishes[b]) {
            if (d->cnt > 0) {
                d->cnt--;
                if (d->cnt == 0) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}
