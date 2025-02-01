#ifndef HASSAKU_UNION_FIND_HPP
#define HASSAKU_UNION_FIND_HPP

#include <vector>

namespace hassaku {

template <class T = int>
class UnionFind {
    std::vector<T> par, rank, siz;

   public:
    // @param n 要素数
    inline UnionFind(T n) {
        par = vector<T>(n, -1);
        rank = vector<T>(n, 0);
        siz = vector<T>(n, 1);
    }

    // xの根を求める
    inline T root(T x) {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    // xとyが同じグループに属するかどうか（根が一致するかどうか）
    inline bool same(T x, T y) { return root(x) == root(y); }

    // xを含むグループとyを含むグループとを併合する
    inline void unite(T x, T y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (rank[x] < rank[y]) swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        siz[x] += siz[y];
    }

    // xを含むグループのサイズ
    inline T size(T x) { return siz[root(x)]; }

    // グループ数
    inline T groups() {
        T res = 0;
        for (T i = 0; i < par.size(); i++) {
            if (par[i] == -1) res++;
        }
        return res;
    }

    // 頂点xが根かどうか
    inline T is_root(T x) { return par[x] == -1; }
};
}  // namespace hassaku

#endif