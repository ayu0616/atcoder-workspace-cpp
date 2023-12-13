#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr double TIME = 2.0;

int N, D, Q;
vi weight, item_rank(100, -1);

vector<vector<char>> item_memo(100, vector<char>(100, '-'));
char compare_weight(int i1, int i2)
{
    if (item_memo[i1][i2] != '-')
        return item_memo[i1][i2];
    rep(i, N)
    {
        char res1 = item_memo[i1][i];
        char res2 = item_memo[i][i2];
        if (res1 != '-' && res1 == res2)
        {
            item_memo[i1][i2] = res1;
            item_memo[i2][i1] = res1 == '=' ? '=' : res1 == '>' ? '<'
                                                                : '>';
            return res1;
        }
    }
    char res;
    if (Q > 0)
    {
        cout << 1 << " " << 1 << " " << i1 << " " << i2 << endl;
        Q--;

        /* dev */
        int w1 = weight[i1];
        int w2 = weight[i2];
        if (w1 > w2)
            res = '>';
        else if (w1 < w2)
            res = '<';
        else
            res = '=';
        /* dev */

        /* prod */
        cin >> res;
        /* prod */
    }
    else
    {
        res = '=';
    }
    item_memo[i1][i2] = res;
    item_memo[i2][i1] = res == '=' ? '=' : res == '>' ? '<'
                                                      : '>';
    return res;
}

map<pair<vi, vi>, char> memo;
char compare_weight(vi s1, vi s2)
{
    sort(all(s1));
    sort(all(s2));
    rep(i, s2.size())
    {
        auto it = find(all(s1), s2[i]);
        if (it != s1.end())
        {
            s1.erase(it);
            s2.erase(s2.begin() + i);
        }
    }
    if (memo[{s1, s2}] != 0)
        return memo[{s1, s2}];
    if (s1.size() == s2.size())
    {
        char prev_memo_res;
        bool flag = true;
        rep(i, s1.size()) rep(j, s2.size())
        {
            char memo_res = item_memo[s1[i]][s2[j]];
            if ((i != 0 && j != 0) && memo_res != prev_memo_res)
            {
                flag = false;
                break;
            }
            prev_memo_res = memo_res;
        }
        if (flag && prev_memo_res != '-')
        {
            memo[{s1, s2}] = prev_memo_res;
            memo[{s2, s1}] = prev_memo_res == '=' ? '=' : prev_memo_res == '>' ? '<'
                                                                               : '>';
            return prev_memo_res;
        }
    }
    char res;
    if (Q > 0)
    {
        if (find(all(s1), 1) != s1.end() && find(all(s2), 1) != s2.end())
        {
            cerr << 1 << endl;
        }
        cout << s1.size() << " " << s2.size() << " " << s1 << " " << s2 << endl;
        Q--;

        /* dev */
        int w1 = 0, w2 = 0;
        for (auto v : s1)
            w1 += weight[v];
        for (auto v : s2)
            w2 += weight[v];
        if (w1 > w2)
            res = '>';
        else if (w1 < w2)
            res = '<';
        else
            res = '=';
        /* dev */

        /* prod */
        cin >> res;
        /* prod */

        memo[{s1, s2}] = res;
        memo[{s2, s1}] = res == '=' ? '=' : res == '>' ? '<'
                                                       : '>';
        if (res == '<')
        {
            for (auto v : s1)
            {
                auto cp = s1;
                cp.erase(find(all(cp), v));
                memo[{cp, s2}] = '<';
                memo[{s2, cp}] = '>';
            }
            rep(i, N)
            {
                auto cp = s2;
                cp.push_back(i);
                sort(all(cp));
                memo[{s1, cp}] = '<';
                memo[{cp, s1}] = '>';
            }
        }
        else if (res == '>')
        {
            for (auto v : s2)
            {
                auto cp = s2;
                cp.erase(find(all(cp), v));
                memo[{s1, cp}] = '>';
                memo[{cp, s1}] = '<';
            }
            rep(i, N)
            {
                auto cp = s1;
                cp.push_back(i);
                sort(all(cp));
                memo[{s2, cp}] = '>';
                memo[{cp, s2}] = '<';
            }
        }
    }
    else
    {
        res = '=';
    }
    return res;
}

vi merge_sort(int l, int r, vvi &assign)
{
    if (l == r)
        return {l};
    int mid = (l + r) / 2;
    auto v1 = merge_sort(l, mid, assign);
    auto v2 = merge_sort(mid + 1, r, assign);
    vi res;
    int i1 = 0, i2 = 0;
    while (i1 < v1.size() && i2 < v2.size())
    {
        char comp_res = compare_weight(assign[v1[i1]], assign[v2[i2]]);
        if (comp_res == '<')
        {
            res.push_back(v1[i1]);
            i1++;
        }
        else
        {
            res.push_back(v2[i2]);
            i2++;
        }
    }
    while (i1 < v1.size())
    {
        res.push_back(v1[i1]);
        i1++;
    }
    while (i2 < v2.size())
    {
        res.push_back(v2[i2]);
        i2++;
    }
    return res;
}

int find_min(int i, int j, vvi &assign)
{
    if (i == j)
        return i;
    int mid = (i + j) / 2;
    int m1 = find_min(i, mid, assign);
    int m2 = find_min(mid + 1, j, assign);
    char comp_res = compare_weight(assign[m1], assign[m2]);
    int res = comp_res == '<' ? m1 : m2;
    return res;
}

int find_max(int i, int j, vvi &assign)
{
    if (i == j)
        return i;
    int mid = (i + j) / 2;
    int m1 = find_max(i, mid, assign);
    int m2 = find_max(mid + 1, j, assign);
    char comp_res = compare_weight(assign[m1], assign[m2]);
    int res = comp_res == '>' ? m1 : m2;
    return res;
}

int find_min(int i, int j, vi &items)
{
    if (i == j)
        return i;
    int mid = (i + j) / 2;
    int m1 = find_min(i, mid, items);
    int m2 = find_min(mid + 1, j, items);
    char comp_res = compare_weight(items[m1], items[m2]);
    int res = comp_res == '<' ? m1 : m2;
    return res;
}

int find_max(int i, int j, vi &items)
{
    if (i == j)
        return i;
    int mid = (i + j) / 2;
    int m1 = find_max(i, mid, items);
    int m2 = find_max(mid + 1, j, items);
    char comp_res = compare_weight(items[m1], items[m2]);
    int res = comp_res == '>' ? m1 : m2;
    return res;
}

void print_ans(vvi &assign, bool comment = false)
{
    if (comment)
    {
        cout << "#c ";
    }
    vi ans(N);
    rep(i, D)
    {
        for (auto v : assign[i])
        {
            ans[v] = i;
        }
    }
    cout << ans << endl;
}

double get_time(time_t &start)
{
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}

int random_int(int l, int r)
{
    return l + rand() % (r - l + 1);
}

int main()
{
    time_t start = clock();
    rep(i, 100) item_memo[i][i] = '=';

    cin >> N >> D >> Q;

    const int Q_MAX = Q;

    /* dev */
    // weight.resize(N);
    // rep(i, N) cin >> weight[i];
    /* dev */

    vvi assign(D);
    vector<vvi> history;

    vi all_items(N);
    rep(i, N) all_items[i] = i;
    // rep(i, D)
    // {
    //     int max_item = all_items[find_max(0, all_items.size() - 1, all_items)];
    //     assign[i].push_back(max_item);
    //     all_items.erase(find(all_items.begin(), all_items.end(), max_item));
    // }
    rep(i, all_items.size()) assign[i % D].push_back(all_items[i]);
    print_ans(assign, true);

    while (Q > 0 && get_time(start) < TIME * 0.6)
    {
        int min_idx = find_min(0, assign.size() - 1, assign), max_idx = find_max(0, assign.size() - 1, assign);
        if (assign[max_idx].size() > 1)
        {
            int max_rand_item_idx = random_int(0, assign[max_idx].size() - 1);
            int max_item = assign[max_idx][max_rand_item_idx];
            auto tmp = assign;
            tmp[min_idx].push_back(max_item);
            tmp[max_idx].erase(tmp[max_idx].begin() + max_rand_item_idx);
            if (compare_weight(tmp[max_idx], assign[min_idx]) != '<')
            {
                assign = tmp;
                print_ans(assign, true);
            }
        }
        else if (Q > Q_MAX * 0.1)
        {
            int random_assign_idx = random_int(0, assign.size() - 1);
            if (assign[random_assign_idx].size() == 1)
                continue;
            int random_item_idx = random_int(0, assign[random_assign_idx].size() - 1);
            int random_item = assign[random_assign_idx][random_item_idx];
            assign[min_idx].push_back(random_item);
            assign[random_assign_idx].erase(assign[random_assign_idx].begin() + random_item_idx);
            print_ans(assign, true);
        }
        // cerr << get_time(start) << endl;
    }

    // cerr << get_time(start) << endl;
    print_ans(assign, true);

    while (Q > 0 && get_time(start) < TIME * 0.9)
    {
        vi all_items(N);
        rep(i, N) all_items[i] = i;
        rep(i, N / 3 * 2 + 1)
        {
            int min_idx = find_min(0, assign.size() - 1, assign), max_idx = find_max(0, assign.size() - 1, assign);
            int min_item;
            if (item_rank[i] != -1)
            {
                min_item = item_rank[i];
            }
            else
            {
                min_item = all_items[find_min(0, all_items.size() - 1, all_items)];
                item_rank[i] = min_item;
            }
            int min_assign_idx = 0;
            rep(j, D)
            {
                if (find(assign[j].begin(), assign[j].end(), min_item) != assign[j].end())
                {
                    min_assign_idx = j;
                    break;
                }
            }
            if (assign[min_assign_idx].size() > 1 && min_idx != min_assign_idx)
            {
                auto tmp = assign;
                tmp[min_idx].push_back(min_item);
                tmp[min_assign_idx].erase(find(tmp[min_assign_idx].begin(), tmp[min_assign_idx].end(), min_item));
                if (Q <= 0 || get_time(start) > TIME * 0.9)
                    break;
                if (compare_weight(tmp[min_assign_idx], assign[min_idx]) != '<' && compare_weight(tmp[min_idx], assign[max_idx]) != '>')
                {
                    assign = tmp;
                    print_ans(assign, true);
                    // cerr << get_time(start) << endl;
                }
            }
            all_items.erase(find(all_items.begin(), all_items.end(), min_item));
        }
    }

    // cerr << get_time(start) << endl;

    while (Q-- > 0)
    {
        cout << 1 << " " << 1 << " " << 0 << " " << 1 << endl;
    }

    print_ans(assign);
    // cerr << get_time(start) << endl;
}
