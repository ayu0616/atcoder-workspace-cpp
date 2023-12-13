#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

bool replacable(int i, int j, vvi c, vi col_cnt, vector<set<int>> &neig)
{
    int cur = c[i][j];
    int n = c.size();
    c[i][j] = 0;
    col_cnt[cur]--;
    col_cnt[0]++;
    int cnt = 0;
    set<int> ne;
    deque<pii> q;
    rep(k, 4){
        int ni = i + dx4[k];
        int nj = j + dy4[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n || c[ni][nj] == 0)
            continue;
        if (neig[c[ni][nj]].find(0) == neig[c[ni][nj]].end())
        {
            return false;
        }
    }
    rep(k, 4)
    {
        int ni = i + dx4[k];
        int nj = j + dy4[k];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n || c[ni][nj] == 0)
            continue;
        if (c[ni][nj] == cur)
        {
            q.push_back({ni, nj});
            c[ni][nj] = 0;
            break;
        }
    }
    while (!q.empty())
    {
        auto [ni, nj] = q.front();
        q.pop_front();
        cnt++;
        rep(k, 4)
        {
            int nni = ni + dx4[k];
            int nnj = nj + dy4[k];
            if (nni < 0 || nni >= n || nnj < 0 || nnj >= n || c[nni][nnj] == 0)
                ne.insert(0);
            else if (c[nni][nnj] == cur)
            {
                q.push_back({nni, nnj});
                c[nni][nnj] = 0;
            }
            else
            {
                ne.insert(c[nni][nnj]);
                c[nni][nnj] = 0;
            }
        }
    }
    bool res = cnt == col_cnt[cur] && ne == neig[cur];
    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vi col_cnt(m + 1, 0);
    vector<set<int>> neig(m + 1);
    vvi c(n, vi(n));
    rep(i, n) rep(j, n)
    {
        cin >> c[i][j];
        col_cnt[c[i][j]]++;
    }
    cout << c << endl;
    rep(i, n) rep(j, n)
    {
        rep(k, 4)
        {
            int ni = i + dx4[k];
            int nj = j + dy4[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= n)
                neig[c[i][j]].insert(0);
            else if (c[ni][nj] != c[i][j])
            {
                neig[c[i][j]].insert(c[ni][nj]);
            }
        }
    }
    deque<pii> q;
    rep(i, n)
    {
        q.push_back({i, 0});
        q.push_back({i, n - 1});
        if (i == 0 || i == n - 1)
            continue;
        q.push_back({0, i});
        q.push_back({n - 1, i});
    }
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop_front();
        if (replacable(i, j, c, col_cnt, neig))
        {
            int cur = c[i][j];
            c[i][j] = 0;
            col_cnt[cur]--;
            col_cnt[0]++;
            cout << c << endl;
            rep(k, 4)
            {
                int ni = i + dx4[k];
                int nj = j + dy4[k];
                if (ni < 0 || ni >= n || nj < 0 || nj >= n || c[ni][nj] == 0)
                    continue;
                q.push_back({ni, nj});
            }
        }
    }
    cout << c << endl;
}
