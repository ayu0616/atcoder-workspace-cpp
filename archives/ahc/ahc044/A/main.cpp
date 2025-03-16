#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <chrono>
#include <random>

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int N, L;
vi T, sorted_T;

int calc_score(const vpii& ans) {
    int cur = 0;
    vi sum(N);
    constexpr int cnt = 1000;
    rep(cnt) {
        sum[cur]++;
        cur = sum[cur] % 2 == 0 ? ans[cur].second : ans[cur].first;
    }
    rep(i, N) { sum[i] *= (L / cnt); }
    int e = 0;
    sort(all(sum));
    rep(i, N) { e += abs(sorted_T[i] - sum[i]); }
    return 1000000 - e;
}

void swap_ans(vpii& ans) {
    int cur = 0;
    vpii sum(N);
    rep(i, N) {
        sum[i].first = 0;
        sum[i].second = i;
    }
    const int cnt = L;
    rep(cnt) {
        sum[cur].first++;
        cur = sum[cur].first % 2 == 0 ? ans[cur].second : ans[cur].first;
    }
    sort(all(sum));

    vpii sorted_T;
    rep(i, N) { sorted_T.emplace_back(T[i], i); }
    sort(all(sorted_T));

    vi mp(N);
    rep(i, N) { mp[sum[i].second] = sorted_T[i].second; }
    rep(i, N) {
        if (ans[i].first != 0) ans[i].first = mp[ans[i].first];
        if (ans[i].second != 0) ans[i].second = mp[ans[i].second];
    }
}

int random_select(const vi& cum, mt19937& engine) {
    std::uniform_int_distribution<int> dist(0, cum.back() - 1);
    int r = dist(engine);
    return upper_bound(all(cum), r) - cum.begin() - 1;
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> L;
    T.resize(N);
    cin >> T;
    sorted_T = T;
    sort(all(sorted_T));

    vi T_cum(N + 1);
    rep(i, N) T_cum[i + 1] = T_cum[i] + T[i];
    // 乱数生成器の初期化
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());

    vpii ans;
    rep(i, N) {
        int a = random_select(T_cum, engine);
        int b = random_select(T_cum, engine);
        ans.emplace_back(a, b);
    }

    // 焼きなまし
    int current_score = calc_score(ans);
    int best_score = current_score;  // 最大スコア用の変数を追加
    auto best_ans = ans;             // ベスト解を保持する変数を追加
    const auto start_time = chrono::steady_clock::now();
    int iteration_count = 0;
    constexpr double MAX_TEMP = 10000;  // 最大温度
    constexpr double MIN_TEMP = 1;      // 最小温度
    constexpr int MAX_MILLIS = 1950;    // 最大時間
    while (true) {
        // 経過時間チェック
        auto now = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - start_time).count();
        if (elapsed >= MAX_MILLIS) break;

        // 温度計算（線形冷却）
        double progress = static_cast<double>(elapsed) / MAX_MILLIS;
        double temp = MAX_TEMP * (1.0 - progress) + MIN_TEMP * progress;

        // 近傍解の生成
        auto new_ans = ans;
        int idx = engine() % N;
        if (engine() % 2 == 0) {
            new_ans[idx].first = random_select(T_cum, engine);
        } else {
            new_ans[idx].second = random_select(T_cum, engine);
        }

        // スコア計算
        int new_score = calc_score(new_ans);
        int delta = new_score - current_score;

        // 確率的に解を採用
        std::uniform_real_distribution<> prob(0.0, 1.0);
        if (delta > 0 || (temp > 0 && exp(delta / temp) > prob(engine))) {
            ans = new_ans;
            current_score = new_score;
            if (current_score > best_score) {  // ベストスコア更新チェック
                best_score = current_score;
                best_ans = ans;
            }
        }

        iteration_count++;
    }

    // 結果出力
    swap_ans(best_ans);
    for (auto [a, b] : best_ans) {  // ベスト解を出力するように変更
        cout << a << " " << b << endl;
    }

#ifndef NDEBUG
    cerr << "Iterations: " << iteration_count << endl;
    cerr << "Final Score: " << calc_score(best_ans) << endl;  // ベスト解のスコアを出力
#endif
}
