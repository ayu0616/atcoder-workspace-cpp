#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int n, m;
int n_move = 5000;
int score = 10000;

struct Move
{
    int v;
    int i;
};

struct State
{
    vvi b;
    int score;
    int n_move;
    vpii history;
    int carried;

    bool operator<(State const &s) const
    {
        return score < s.score;
    }

    void move(int from, int i, int to)
    {
        if (i >= b[from].size())
            return;
        history.push_back({b[from][i], to + 1});
        score = max(score - (b[from].size() - i + 1), 1);
        n_move--;
        for (int j = i; j < b[from].size(); ++j)
        {
            b[to].push_back(b[from][j]);
        }
        b[from].resize(i);
    }

    void carry(int from)
    {
        if (b[from].back() != carried + 1)
        {
            throw "error in carry";
        }
        history.push_back({b[from].back(), 0});
        b[from].pop_back();
        carried++;
    }

    pair<int, int> find_min()
    {
        int min_i = -1, min_j = -1;
        int min_v = 10000;
        rep(i, m)
        {
            if (b[i].size() == 0)
                continue;
            rep(j, b[i].size())
            {
                if (b[i][j] < min_v)
                {
                    min_v = b[i][j];
                    min_i = i;
                    min_j = j;
                }
            }
        }
        if (min_v != carried + 1)
        {
            throw "error in find_min";
        }
        return {min_i, min_j};
    }

    vector<State> find_nexts()
    {
        auto [min_i, min_j] = find_min();
        vector<State> nexts;
        rep(i, m)
        {
            if (i == min_i)
                continue;
            State next = {b, score, n_move, history, carried};
            next.move(min_i, min_j + 1, i);
            next.carry(min_i);
            nexts.push_back(next);
        }
        return nexts;
    }

    State transition()
    {
        auto nexts = find_nexts();
        if (nexts[0].carried == n)
            return nexts[0];
        int max_score = 0;
        State max_next;
        rep(i, nexts.size())
        {
            int j = (i + carried) % nexts.size();
            auto &next = nexts[j];
            int max_s = 0;
            auto nexts2 = next.find_nexts();
            for (auto const &next2 : nexts2)
            {
                chmax(max_s, next2.score);
            }
            if (chmax(max_score, max_s))
                max_next = next;
        }
        return max_next;
    }
};

vi calc_under_min(vi const &m)
{
    if (m.size() == 0)
        return vi(0);
    vi res(m.size());
    res[0] = m[0];
    rep(i, m.size() - 1) res[i + 1] = min(res[i], m[i + 1]);
    return res;
}

// @brief 箱を移動する
// @param b 山の状態
// @param from 移動する山の番号
// @param i これとそれより上の箱を移動する
// @param to 移動先の箱の番号
void move(vvi &b, int from, int i, int to, bool print = false)
{
    if (i >= b[from].size())
        return;
    n_move--;
    score = max(score - (b[from].size() - i + 1), 1);
    if (print)
        cout << b[from][i] << " " << to + 1 << endl;
    for (int j = i; j < b[from].size(); ++j)
    {
        b[to].push_back(b[from][j]);
    }
    b[from].resize(i);
}

void carry(vvi &b, int from, bool print = false)
{
    if (print)
        cout << b[from].back() << " " << 0 << endl;
    b[from].pop_back();
}

int main()
{
    cin >> n >> m;
    vvi b(m, vi(n / m));
    rep(i, m) rep(j, n / m) cin >> b[i][j];
    vvi under_min;
    rep(i, m) under_min.push_back(calc_under_min(b[i]));

    int carried = 0;
    State cur = {b, 10000, 5000, {}, 0};
    while (carried < n)
    {
        cur = cur.transition();
        carried++;
    }
    for (auto const &[v, i] : cur.history)
    {
        cout << v << " " << i << endl;
    }
    debug(n_move);
    debug(cur.score);
}

// int main()
// {
//     cin >> n >> m;
//     vvi b(m, vi(n / m));
//     rep(i, m) rep(j, n / m) cin >> b[i][j];
//     vvi under_min;
//     rep(i, m) under_min.push_back(calc_under_min(b[i]));

//     int carried = 0;
//     while (carried < n)
//     {
//         vi::iterator it;
//         int mountain = -1;
//         rep(i, m)
//         {
//             if ((it = find(all(b[i]), carried + 1)) != b[i].end())
//             {
//                 mountain = i;
//                 break;
//             }
//         }
//         int min_max = 0;
//         int min_max_i = -1;
//         rep(i, m){
//             if(i==mountain)continue;
//             if(under_min[i].size()==0)continue;
//             if(under_min[i].back()>min_max){
//                 min_max = under_min[i].back();
//                 min_max_i = i;
//             }
//         }
//         if(min_max_i==-1)min_max_i=(mountain+1)%m;
//         move(b, mountain, it - b[mountain].begin() + 1, min_max_i, true);
//         carry(b, mountain, true);
//         under_min[mountain] = calc_under_min(b[mountain]);
//         under_min[min_max_i] = calc_under_min(b[min_max_i]);
//         carried++;
//     }
//     debug(n_move);
//     debug(score);
// }
