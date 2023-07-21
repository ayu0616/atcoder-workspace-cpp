#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int n, m = 0;
vi p;
vvi b;
const int MAX_M = 2 * 1000;

struct State
{
    int m;
    int dist;
    vi p;
    int i;
    int j;
    vvi prev;

    bool operator<(const State &rhs) const
    {
        return dist < rhs.dist;
    }
};

int calc_dist(vi &p)
{
    int dist = 0;
    rep(i, n) dist += abs(p[i] - i - 1);
    return dist;
}

vector<int> replace(vector<int> p, int i, int j)
{
    vector<int> Q(n - 2), new_p(n);
    rep(k, n)
    {
        if (k < i)
            Q[k] = p[k];
        if (k == i || k == i + 1)
            continue;
        else
            Q[k - 2] = p[k];
    }
    rep(k, j)
    {
        new_p[k] = Q[k];
    }
    new_p[j] = p[i];
    new_p[j + 1] = p[i + 1];
    rep2(k, j + 2, n)
    {
        new_p[k] = Q[k - 2];
    }
    return new_p;
}

int main()
{
    cin >> n;
    p = vi(n);
    rep(i, n) cin >> p[i];

    priority_queue<State *> q;
    set<State *> used;
    State *s = new State();
    s->m = 0;
    s->dist = calc_dist(p);
    s->p = p;
    s->i = -1;
    s->j = -1;
    q.push(s);

    while (!q.empty())
    {
        State *s = q.top();
        used.insert(s);
        q.pop();
        State st = *s;
        // debug(st.dist);
        if (st.dist == 0)
        {
            cout << "Yes" << endl;
            cout << st.m << endl;
            for (auto v : st.prev)
            {
                cout << v[0] + 1 << " " << v[1] + 1 << endl;
            }
            return 0;
        }
        if (st.m > MAX_M)
        {
            cout << "No" << endl;
            return 0;
        }
        rep(i, n - 1) rep(j, n - 1)
        {
            vi p1 = replace(st.p, i, j);
            State *next_s = new State();
            next_s->m = st.m + 1;
            next_s->dist = calc_dist(p1);
            next_s->p = p1;
            next_s->i = i;
            next_s->j = j;
            next_s->prev = st.prev;
            next_s->prev.push_back({i, j});
            if (next_s->dist == 0)
            {
                cout << "Yes" << endl;
                cout << next_s->m << endl;
                for (auto v : next_s->prev)
                {
                    cout << v[0] + 1 << " " << v[1]  << endl;
                }
                return 0;
            }
            q.push(next_s);
        }
    }

    // b = vvi(n);
    // rep(i, n) rep2(j, i + 1, n)
    // {
    //     if (p[i] > p[j])
    //     {
    //         b[i].push_back(j);
    //     }
    // }
    // rep(i, n) cout << i << ": " << b[i] << endl;
}