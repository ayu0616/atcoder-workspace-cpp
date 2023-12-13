#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N;
string R, C;

bool row_check(vector<string> &grid, ll row)
{
    char fc = '.';
    rep(col, N)
    {
        if (grid[row][col] != '.')
        {
            fc = grid[row][col];
            break;
        }
    }
    if (fc != '.' && fc != R[row])
        return false;
    return true;
}

bool col_check(vector<string> &grid, ll col)
{
    char fc = '.';
    rep(row, N)
    {
        if (grid[row][col] != '.')
        {
            fc = grid[row][col];
            break;
        }
    }
    if (fc != '.' && fc != C[col])
        return false;
    int cnt[3] = {0, 0, 0};
    rep(row, N)if(grid[row][col] != '.') cnt[grid[row][col] - 'A']++;
    if(cnt[0] > 1 || cnt[1] > 1 || cnt[2] > 1) return false;
    return true;
}

bool check(vector<string> &grid)
{
    rep(row, N)
    {
        if (!row_check(grid, row))
            return false;
    }
    rep(col, N)
    {
        if (!col_check(grid, col))
            return false;
    }
    return true;
}

void gen(vector<char> cand, string s, vector<string> &res)
{
    if (s.size() == N)
    {
        res.push_back(s);
    }
    else
    {
        for (auto c : cand)
        {
            auto tmp = cand;
            string t = s + c;
            tmp.erase(find(tmp.begin(), tmp.end(), c));
            gen(tmp, t, res);
        }
    }
}

vector<string> perms;

vector<string> ans;
bool solve(vector<string> grid, ll row)
{
    if (row == N)
    {
        if (check(grid))
        {
            ans = grid;
            return true;
        }
    }
    else
    {
        for (auto perm : perms)
        {
            grid[row] = perm;
            bool ok = true;
            ok &= row_check(grid, row);
            rep(col, N) ok &= col_check(grid, col);
            if (!ok)
                continue;
            if (solve(grid, row + 1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin >> N >> R >> C;
    vector<string> grid(N, string(N, '.'));
    vector<char> cand(N);
    rep(i, N) cand[i] = 'A' + i;
    rep(i, N - 3) cand[i + 3] = '.';
    gen(cand, "", perms);
    if (solve(grid, 0))
    {
        cout << "Yes" << endl;
        rep(i, N) cout << ans[i] << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
