#include "../../lib.hpp"

int N, M, si, sj;

int calc_score(vpii &ans) {
    int cost = 0;
    cost += abs(ans[0].first - si) + abs(ans[0].second - sj) + 1;
    rep(i, ans.size() - 1) { cost += abs(ans[i].first - ans[i + 1].first) + abs(ans[i].second - ans[i + 1].second) + 1; }
    return 10000 - cost;
}

int main() {
    cin >> N >> M >> si >> sj;
    vector<string> A(N), t(M);
    cin >> A >> t;

    map<char, vpii> positions;
    rep(i, N) rep(j, N) { positions[A[i][j]].emplace_back(i, j); }

    vpii ans;
    rep(i, M) {
        for (auto c : t[i]) {
            int min_d = 1e9;
            int tmp_i, tmp_j;
            for (auto p : positions[c]) {
                int d = abs(p.first - si) + abs(p.second - sj);
                if (d < min_d) {
                    min_d = d;
                    tmp_i = p.first;
                    tmp_j = p.second;
                }
            }
            ans.emplace_back(tmp_i, tmp_j);
            si = tmp_i, sj = tmp_j;
        }
    }

    assert(ans.size() <= 5000);
    cerr << calc_score(ans) << endl;
    rep(i, ans.size()) cout << ans[i] << endl;
}
