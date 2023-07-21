#include <bits/stdc++.h>
using namespace std;

/* これらは与えられているものとする */
int n, s;                      // 頂点数, 始点
vector<set<pair<int, int>>> g; // グラフ{隣接頂点, 重み}
/* ここまで */

vector<int> d;                                               // 最短距離
priority_queue<pair<int, int>, vector<int>, greater<int>> q; // 優先度付きキュー{最短距離, 頂点}

int main()
{
    d.resize(n);
    for (int i = 0; i < n; i++)
        d[i] = INT_MAX; // 暫定最短距離を無限大に初期化
    d[s] = 0;           // 始点の距離を0に初期化

    q.push({0, s}); // 始点を優先度付きキューに入れる
    while (!q.empty())
    {
        int v = q.top().second; // キューの先頭の頂点を取り出す
        q.pop();
        for (auto e : g[v]) // vから出る辺を走査
        {
            int u = e.first;  // 辺の行き先
            int c = e.second; // 辺の重み
            if (d[u] > d[v] + c)
            {
                d[u] = d[v] + c; // 最短距離を更新
                q.push({d[u], u}); // キューに頂点を入れる
            }
        }
    }
}