#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

class UnionFind {
   public:
    UnionFind(int n) : parent(n), rank(n, 0) { iota(parent.begin(), parent.end(), 0); }

    int find(int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) swap(rootU, rootV);
            parent[rootV] = rootU;
            if (rank[rootU] == rank[rootV]) rank[rootU]++;
            return true;
        }
        return false;
    }

   private:
    vector<int> parent;
    vector<int> rank;
};

class KruskalMST {
   public:
    KruskalMST(int n, const vector<Edge>& edges) : n(n), mst_weight(0) {
        UnionFind uf(n);
        for (const auto& edge : edges) {
            if (uf.unite(edge.u, edge.v)) {
                mst_weight += edge.weight;
                mst_edges.push_back(edge);
                mst_max_edge_weight = edge.weight;
            }
        }
    }

    int get_mst_weight() const { return mst_weight; }

    void process_query(const Edge& new_edge) {
        if (new_edge.weight > mst_max_edge_weight) {
            return;
        }
        mst_edges.push_back(new_edge);
        UnionFind uf(n);
        sort(mst_edges.begin(), mst_edges.end());

        int new_mst_weight = 0;
        int new_mst_max_edge_weight = 0;
        vector<Edge> new_mst_edges;
        for (const auto& edge : mst_edges) {
            if (uf.unite(edge.u, edge.v)) {
                new_mst_weight += edge.weight;
                new_mst_edges.push_back(edge);
                new_mst_max_edge_weight = edge.weight;
            }
        }

        mst_weight = new_mst_weight;
        mst_edges = new_mst_edges;
        mst_max_edge_weight = new_mst_max_edge_weight;
    }

   private:
    int n;
    int mst_weight;
    int mst_max_edge_weight;
    vector<Edge> mst_edges;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    vector<Edge> edges(N - 1);
    for (int i = 0; i < N - 1; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;  // 0-indexed
        edges[i].v--;  // 0-indexed
    }

    vector<Edge> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].u >> queries[i].v >> queries[i].weight;
        queries[i].u--;  // 0-indexed
        queries[i].v--;  // 0-indexed
    }

    KruskalMST mst(N, edges);

    for (const auto& query : queries) {
        mst.process_query(query);
        cout << mst.get_mst_weight() << "\n";
    }

    return 0;
}
