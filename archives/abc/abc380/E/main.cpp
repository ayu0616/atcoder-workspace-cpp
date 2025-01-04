#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct UF {
   private:
    vector<int> siz, par, col;

   public:
    UF(int n) {
        siz.assign(n, 1);
        par.assign(n, -1);
        col.resize(n);
        iota(all(col), 0);
    }

    int root(int x) {
        if (par[x] == -1) return x;
        return par[x] = root(par[x]);
    }

    int unite(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb) return ra;
        if (ra > rb) swap(ra, rb);
        par[rb] = ra;
        siz[ra] += siz[rb];
        return ra;
    }

    int size(int x) { return siz[root(x)]; }

    void write_color(int x, int c) {
        int rt = root(x);
        col[rt] = c;
    }

    int color(int x) {
        int rt = root(x);
        return col[rt];
    }
};

struct Info {
    int begin, end;
    int color;
};

int main() {
    cout << fixed << setprecision(18);
    ll N, Q;
    cin >> N >> Q;
    vi color_cnt(N, 1);
    UF uf(N);
    rep(Q) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, c;
            cin >> x >> c;
            x--;
            c--;
            if (uf.color(x) == c) continue;

            int size = uf.size(x);

            color_cnt[uf.color(x)] -= size;
            uf.write_color(x, c);
            color_cnt[uf.color(x)] += size;


            int l = uf.root(x);
            if (l - 1 >= 0) {
                if (uf.color(l - 1) == uf.color(x)) {
                    uf.unite(x, l - 1);
                }
            }
            if (l + size < N) {
                if (uf.color(l + size) == uf.color(x)) {
                    uf.unite(l + size, x);
                }
            }
        } else {
            int c;
            cin >> c;
            c--;
            cout << color_cnt[c] << endl;
        }
    }
}
