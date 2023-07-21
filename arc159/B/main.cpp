#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    Graph g(6);
    g.add_edge(0, 1, true);
    g.add_edge(0, 3, true);
    g.add_edge(1, 3, true);
    g.add_edge(2, 3, true);
    g.add_edge(2, 4, true);
    g.add_edge(4, 5, true);
    g.add_edge(3, 5, true);
    g.add_edge(5, 2, true);

    cout << g.topological_sort() << endl;
}
