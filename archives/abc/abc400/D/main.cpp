#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Score {
    ll cnt, dist;
    Score(ll cnt, ll dist) : cnt(cnt), dist(dist) {}

    bool operator<(const Score& other) const {
        if (cnt != other.cnt) return cnt > other.cnt;
        return dist > other.dist;
    }
};

int main() {
    cout << fixed << setprecision(18);
    ll H, W;
    cin >> H >> W;
    vs S(H);
    cin >> S;
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    A--, B--, C--, D--;

    priority_queue<pair<Score, pll>> pq;
    pq.push({Score(0, abs(A - C) + abs(B - D)), {A, B}});
    vector<vector<Score>> high(H, vector<Score>(W, Score(LLONG_MAX, LLONG_MAX)));
    while (!pq.empty()) {
        auto [score, pos] = pq.top();
        pq.pop();
        auto [i, j] = pos;
        if (i == C && j == D) {
            cout << score.cnt << endl;
            return 0;
        }
        rep(k, 4) {
            ll ni = i + dx4[k];
            ll nj = j + dy4[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (S[ni][nj] == '#') continue;
            Score new_score(score.cnt, abs(ni - C) + abs(nj - D));
            if (high[ni][nj] < new_score) {
                pq.push({new_score, {ni, nj}});
                high[ni][nj] = new_score;
            }
        }
        rep(k, 4) {
            ll ni = i + dx4[k];
            ll nj = j + dy4[k];
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (S[ni][nj] != '#') continue;
            Score new_score(score.cnt + 1, abs(ni - C) + abs(nj - D));
            if (high[ni][nj] < new_score) {
                pq.push({new_score, {ni, nj}});
                high[ni][nj] = new_score;
            }
        }
        rep(k, 4) {
            ll ni = i + dx4[k] * 2;
            ll nj = j + dy4[k] * 2;
            if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
            if (S[ni][nj] != '#') continue;
            Score new_score(score.cnt + 1, abs(ni - C) + abs(nj - D));
            if (high[ni][nj] < new_score) {
                pq.push({new_score, {ni, nj}});
                high[ni][nj] = new_score;
            }
        }
    }
}
