#include <bits/stdc++.h>
using namespace std;
using Int = long long;
template <typename T1, typename T2>
inline void chmin(T1 &a, T2 b) {
    if (a > b) a = b;
}
template <typename T1, typename T2>
inline void chmax(T1 &a, T2 b) {
    if (a < b) a = b;
}

class EulerTourForVertex {
   private:
    vector<Int> ls, rs, par;
    Int pos;

    void dfs(Int v, Int p) {
        par[v] = p;
        ls[v] = pos++;
        for (Int u : G[v])
            if (u != p) dfs(u, v);
        rs[v] = pos;
    }

   public:
    vector<vector<Int> > G;

    EulerTourForVertex() {}
    EulerTourForVertex(Int n) : ls(n), rs(n), par(n), G(n) {}

    void add_edge(Int u, Int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(Int r = 0) {
        pos = 0;
        dfs(r, -1);
    }

    Int idx(Int v) { return ls[v]; }
    Int parent(Int v) { return par[v]; };

    template <typename F>
    void exec(Int v, F f) {
        f(ls[v], rs[v]);
    }
};

template <typename T, typename E>
struct SegmentTree {
    using F = function<T(T, T)>;
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;
    Int n, height;
    F f;
    G g;
    H h;
    T ti;
    E ei;
    vector<T> dat;
    vector<E> laz;
    SegmentTree(F f, G g, H h, T ti, E ei) : f(f), g(g), h(h), ti(ti), ei(ei) {}

    void init(Int n_) {
        n = 1;
        height = 0;
        while (n < n_) n <<= 1, height++;
        dat.assign(2 * n, ti);
        laz.assign(2 * n, ei);
    }
    void build(const vector<T> &v) {
        Int n_ = v.size();
        init(n_);
        for (Int i = 0; i < n_; i++) dat[n + i] = v[i];
        for (Int i = n - 1; i; i--) dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }
    inline T reflect(Int k) { return laz[k] == ei ? dat[k] : g(dat[k], laz[k]); }
    inline void eval(Int k) {
        if (laz[k] == ei) return;
        laz[(k << 1) | 0] = h(laz[(k << 1) | 0], laz[k]);
        laz[(k << 1) | 1] = h(laz[(k << 1) | 1], laz[k]);
        dat[k] = reflect(k);
        laz[k] = ei;
    }
    inline void thrust(Int k) {
        for (Int i = height; i; i--) eval(k >> i);
    }
    inline void recalc(Int k) {
        while (k >>= 1) dat[k] = f(reflect((k << 1) | 0), reflect((k << 1) | 1));
    }
    void update(Int a, Int b, E x) {
        thrust(a += n);
        thrust(b += n - 1);
        for (Int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) laz[l] = h(laz[l], x), l++;
            if (r & 1) --r, laz[r] = h(laz[r], x);
        }
        recalc(a);
        recalc(b);
    }
    void set_val(Int a, T x) {
        thrust(a += n);
        dat[a] = x;
        laz[a] = ei;
        recalc(a);
    }
    T query(Int a, Int b) {
        thrust(a += n);
        thrust(b += n - 1);
        T vl = ti, vr = ti;
        for (Int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, reflect(l++));
            if (r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }

    template <typename C>
    Int find(Int st, C &check, T &acc, Int k, Int l, Int r) {
        if (l + 1 == r) {
            acc = f(acc, reflect(k));
            return check(acc) ? k - n : -1;
        }
        eval(k);
        Int m = (l + r) >> 1;
        if (m <= st) return find(st, check, acc, (k << 1) | 1, m, r);
        if (st <= l && !check(f(acc, dat[k]))) {
            acc = f(acc, dat[k]);
            return -1;
        }
        Int vl = find(st, check, acc, (k << 1) | 0, l, m);
        if (~vl) return vl;
        return find(st, check, acc, (k << 1) | 1, m, r);
    }
    template <typename C>
    Int find(Int st, C &check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }
};

struct FastIO {
    FastIO() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fastio_beet;

template <typename T>
struct Ushi {
    using F = function<T(T, T)>;
    Int n;
    F f;
    T ti;
    vector<T> dat;
    Ushi(){};
    Ushi(F f, T ti) : f(f), ti(ti) {}
    void init(Int n_) {
        n = 1;
        while (n < n_) n <<= 1;
        dat.assign(n << 1, ti);
    }
    void build(const vector<T> &v) {
        Int n_ = v.size();
        init(n_);
        for (Int i = 0; i < n_; i++) dat[n + i] = v[i];
        for (Int i = n - 1; i; i--) dat[i] = f(dat[(i << 1) | 0], dat[(i << 1) | 1]);
    }
    void set_val(Int k, T x) {
        dat[k += n] = x;
        while (k >>= 1) dat[k] = f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
    }
    T query(Int a, Int b) {
        T vl = ti, vr = ti;
        for (Int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, dat[l++]);
            if (r & 1) vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }
    template <typename C>
    Int find(Int st, C &check, T &acc, Int k, Int l, Int r) {
        if (l + 1 == r) {
            acc = f(acc, dat[k]);
            return check(acc) ? k - n : -1;
        }
        Int m = (l + r) >> 1;
        if (m <= st) return find(st, check, acc, (k << 1) | 1, m, r);
        if (st <= l && !check(f(acc, dat[k]))) {
            acc = f(acc, dat[k]);
            return -1;
        }
        Int vl = find(st, check, acc, (k << 1) | 0, l, m);
        if (~vl) return vl;
        return find(st, check, acc, (k << 1) | 1, m, r);
    }
    template <typename C>
    Int find(Int st, C &check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }
};

// INSERT ABOVE HERE
signed main() {
    Int n;
    cin >> n;
    EulerTourForVertex G(n);
    for (Int i = 1; i < n; i++) {
        Int x, y;
        cin >> x >> y;
        x--;
        y--;
        G.add_edge(x, y);
    }
    G.build();

    using P = pair<Int, Int>;
    auto f = [&](P a, P b) { return P(a.first + b.first, a.second + b.second); };
    auto g = [&](P a, Int b) { return P(a.first + b * a.second, a.second); };
    auto h = [&](Int a, Int b) { return a + b; };

    P ti(0, 0);
    Int ei = 0;
    SegmentTree<P, Int> seg(f, g, h, ti, ei);
    seg.build(vector<P>(n, P(0, 1)));

    Ushi<Int> num(h, 0);
    num.build(vector<Int>(n, 0));

    vector<Int> ans(n, 0);
    for (Int v = 0; v < n; v++) {
        Int sum = 0;
        for (Int u : G.G[v]) {
            if (G.parent(v) != u) {
                auto func = [&](Int l, Int r) { sum += num.query(l, r); };
                G.exec(u, func);
            } else {
                auto func = [&](Int l, Int r) { sum += v - num.query(l, r); };
                G.exec(v, func);
            }
        }
        // cout<<v<<":"<<sum<<endl;

        for (Int u : G.G[v]) {
            Int res = 0;
            if (G.parent(v) != u) {
                auto func = [&](Int l, Int r) { res = num.query(l, r); };
                auto upd0 = [&](Int l, Int r) { seg.update(l, r, sum - res); };
                G.exec(u, func);
                G.exec(u, upd0);
                // cout<<u<<" "<<res<<endl;
            } else {
                auto func = [&](Int l, Int r) { res = v - num.query(l, r); };
                auto upd1 = [&](Int l, Int r) { seg.update(l, r, sum - res); };
                auto upd2 = [&](Int l, Int r) { seg.update(l, r, res - sum); };
                G.exec(v, func);
                G.exec(0, upd1);
                G.exec(v, upd2);
                // cout<<u<<" "<<res<<endl;
            }
        }
        ans[v] += sum;
        num.set_val(G.idx(v), 1);
    }

    for (Int i = 0; i < n; i++) cout << ans[i] + seg.query(G.idx(i), G.idx(i) + 1).first << " \n"[i + 1 == n];
    return 0;
}
