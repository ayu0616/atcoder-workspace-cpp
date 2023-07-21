#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll calc_score(int n, int k, int s)
{
    if (n < k)
    {
        return 1e6 * (n + 1) / k;
    }
    return 1e6 * (1 + 1e8 / (s + 1e7));
}

bool dfs(Graph &g, int s, vi &visited, vi &B, set<int> &use, map<pii, int> edges)
{
    bool res;
    visited[s] = 1;
    for (auto e : g[s])
    {
        if (visited[e.to])
        {
            continue;
        }
        res = use.find(e.to) != use.end();
        res |= dfs(g, e.to, visited, B, use, edges);
        if (res)
            B[edges[{min(s, e.to.id), max(s, e.to.id)}]] = 1;
    }
    return res;
}

struct Node
{
    vector<int> point;
    Node *left;
    Node *right;
};

Node *build_kdtree(vector<vector<int>> &points, int depth = 0)
{
    if (points.empty())
    {
        return nullptr;
    }

    int k = points[0].size();
    int axis = depth % k;

    sort(points.begin(), points.end(), [&](const vector<int> &a, const vector<int> &b)
         { return a[axis] < b[axis]; });

    int mid = points.size() / 2;
    Node *node = new Node;
    node->point = points[mid];
    node->left = build_kdtree(vector<vector<int>>(points.begin(), points.begin() + mid), depth + 1);
    node->right = build_kdtree(vector<vector<int>>(points.begin() + mid + 1, points.end()), depth + 1);

    return node;
}

void search_kdtree(Node *node, vector<int> &point, Node *&best_node, double &best_dist, int depth = 0)
{
    if (node == nullptr)
    {
        return;
    }

    double dist = 0;
    for (int i = 0; i < point.size(); i++)
    {
        dist += pow(point[i] - node->point[i], 2);
    }
    dist = sqrt(dist);

    if (dist < best_dist)
    {
        best_node = node;
        best_dist = dist;
    }

    int k = point.size();
    int axis = depth % k;

    if (point[axis] < node->point[axis])
    {
        search_kdtree(node->left, point, best_node, best_dist, depth + 1);
        if (point[axis] + best_dist >= node->point[axis])
        {
            search_kdtree(node->right, point, best_node, best_dist, depth + 1);
        }
    }
    else
    {
        search_kdtree(node->right, point, best_node, best_dist, depth + 1);
        if (point[axis] - best_dist <= node->point[axis])
        {
            search_kdtree(node->left, point, best_node, best_dist, depth + 1);
        }
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    Graph g(n);
    vi x(n), y(n), a(k), b(k);
    vvi xy(n, vi(2));
    set<pii> nodes;
    map<pii, int> edges, node_pos;
    rep(i, n)
    {
        cin >> x[i] >> y[i];
        xy[i] = {x[i], y[i]};
        nodes.insert({x[i], y[i]});
        node_pos[{x[i], y[i]}] = i;
    }
    rep(i, m)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--;
        v--;
        g.add_edge(u, v, w);
        edges[{min(u, v), max(u, v)}] = i;
    }
    rep(i, k)
    {
        cin >> a[i] >> b[i];
    }

    vi p(n, 0), B(m, 0);
    set<int> use;
    use.insert(0);

    Node *root = build_kdtree(xy);

    rep(i, k)
    {
        Node *best_node = nullptr;
        double best_dist = numeric_limits<double>::max();
        search_kdtree(root, {a[i], b[i]}, best_node, best_dist);
        int pos = node_pos[pii(best_node->point)];
        ll d = (a[i] - best_node->point[0]) * (a[i] - best_node->point[0]) + (b[i] - best_node->point[1]) * (b[i] - best_node->point[1]);
        p[pos] = min(sqrt(d), 4999);
        use.insert(pos);
    }

    vi visited(n, 0);
    dfs(g, 0, visited, B, use, edges);

    cout << p << endl;
    cout << B << endl;
}
