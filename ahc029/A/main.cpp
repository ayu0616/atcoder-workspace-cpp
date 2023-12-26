#include "../../lib.hpp"

#if HASSAKU_DEBUG
#define is_debug true
#else
#define is_debug false
#endif

constexpr double h_v_cospa_threshold = 1;    // この値以下のコスパのプロジェクトは捨てる
constexpr double p_w_cospa_threshold = 1.5;  // この値以上のコスパのカードを選ぶ

int N, M, K, T;
int turn = 0;                  // 現在のターン
ll money = 0;                  // 所持金
int cap_inc_count = 0;         // 増資した回数
int want_to_remove_count = 0;  // 捨てたいプロジェクトの数
struct Project;
struct Card;
struct CardCandidate;
vector<Project> projects;               // 進行中のプロジェクト
queue<Project> debug_projects;          // デバッグ用のプロジェクト
queue<CardCandidate> debug_candidates;  // デバッグ用のカード候補

enum class CardType {
    NORMAL_WORK,      // 通常労働
    FULL_POWER_WORK,  // 全力労働
    CANCEL,           // キャンセル
    CONVERT,          // 業務転換
    CAPITAL_INCREASE  // 増資
};

struct Card {
    CardType type;  // カードのタイプ
    int w;          // 労働力

    // パフォーマンス
    int performance() const {
        switch (type) {
            case CardType::NORMAL_WORK:
                return w;
            case CardType::FULL_POWER_WORK:
                return w * M;
            default:
                return 0;
        }
    }
};

struct Cards {
    vector<Card> cards;

    Card& operator[](int i) { return cards[i]; }
    const Card& operator[](int i) const { return cards[i]; }

    void resize(int N) { cards.resize(N); }

    int convert_idx() const {
        rep(i, cards.size()) {
            if (cards[i].type == CardType::CONVERT) return i;
        }
        return -1;
    }

    int cancel_idx() const {
        rep(i, cards.size()) {
            if (cards[i].type == CardType::CANCEL) return i;
        }
        return -1;
    }

    int capital_increase_idx() const {
        rep(i, cards.size()) {
            if (cards[i].type == CardType::CAPITAL_INCREASE) return i;
        }
        return -1;
    }

    vi performance_order_idx() const {
        vi r;
        rep(i, cards.size()) {
            if (cards[i].type == CardType::NORMAL_WORK || cards[i].type == CardType::FULL_POWER_WORK) r.push_back(i);
        }
        sort(all(r), [&](int i, int j) { return cards[i].performance() > cards[j].performance(); });
        return r;
    }
};

Cards cards;  // 手持ちのカード

// カード候補
struct CardCandidate : Card {
    int p;  // コスト
    int id;

    // コストパフォーマンス
    double cost_performance() const {
        int performance = Card::performance();
        if (p == 0) return 0;
        return static_cast<double>(performance) / p;
    }
};

struct Project {
    int rest;   // 残務量
    int value;  // 価値

    // コストパフォーマンス
    double cost_performance() const { return static_cast<double>(value) / rest; }

    // 完了したかどうか
    bool is_completed() const { return rest <= 0; }

    // 高いコスパかどうか
    bool is_high_cospa() const { return cost_performance() >= h_v_cospa_threshold; }

    static vi cospa_order_idx() {
        vi r(M);
        rep(i, M) r[i] = i;
        sort(all(r), [&](int i, int j) { return projects[i].cost_performance() > projects[j].cost_performance(); });
        return r;
    }
};

CardCandidate debug_card_pop() {
    CardCandidate c = debug_candidates.front();
    debug_candidates.pop();
    c.w *= pow(2, cap_inc_count);
    c.p *= pow(2, cap_inc_count);
    return c;
}

Project debug_project_pop() {
    Project p = debug_projects.front();
    debug_projects.pop();
    p.rest *= pow(2, cap_inc_count);
    p.value *= pow(2, cap_inc_count);
    return p;
}

// 業務転換が必要かどうか
bool have_to_convert() { return want_to_remove_count > M * 3 / 4; }

// 初期値の入力
void init_in() {
    cin >> N >> M >> K >> T;
    cards.resize(N);
    projects.resize(M);
    if (is_debug) {
        rep(i, M) {
            int h, v;
            cin >> h >> v;
            projects[i] = {h, v};
            if (!projects[i].is_high_cospa()) want_to_remove_count++;
        }
        rep(i, T) rep(j, M) {
            int h, v;
            cin >> h >> v;
            debug_projects.push({h, v});
        }
        rep(i, N) {
            int t, w;
            cin >> t >> w;
            cards[i] = {static_cast<CardType>(t), w};
        }
        rep(i, T) rep(j, K) {
            int t, w, p;
            cin >> t >> w >> p;
            debug_candidates.push({static_cast<CardType>(t), w, p, (int)j});
        }
    } else {
        rep(i, N) {
            int t, w;
            cin >> t >> w;
            cards[i] = {static_cast<CardType>(t), w};
        }
        rep(i, M) {
            int h, v;
            cin >> h >> v;
            projects[i] = {h, v};
            if (!projects[i].is_high_cospa()) want_to_remove_count++;
        }
    }
}

// 出すカードと対象プロジェクトの選択
pii choose_card() {
    int convert_idx = cards.convert_idx();
    int cancel_idx = cards.cancel_idx();
    int capital_increase_idx = cards.capital_increase_idx();
    if (have_to_convert() && convert_idx != -1) {
        int c = convert_idx;
        return {c, 0};
    }
    if (want_to_remove_count >= 1 && cancel_idx != -1) {
        int c = cancel_idx;
        int p = 0;
        double min_cospa = 1e9;
        rep(i, M) {
            if (chmin(min_cospa, projects[i].cost_performance())) {
                p = i;
            }
        }
        return {c, p};
    }
    if (capital_increase_idx != -1) {
        int c = capital_increase_idx;
        return {c, 0};
    }

    double max_cost_performance = 0;
    int max_cost_performance_index = -1;
    rep(i, M) {
        if (chmax(max_cost_performance, projects[i].cost_performance())) {
            max_cost_performance_index = i;
        }
    }
    int max_performance_card_index = -1, max_performance_card = -1;
    rep(i, N) {
        if (chmax(max_performance_card, cards[i].performance())) {
            max_performance_card_index = i;
        }
    }
    int p = max_cost_performance_index;
    int c = max_performance_card_index;

    if (c == -1) {
        c = 0;
    }

    return {c, p};
}

// プロジェクトの更新
void update_project(int c, int p) {
    Card card = cards[c];
    if (card.type == CardType::FULL_POWER_WORK || card.type == CardType::CONVERT || card.type == CardType::CAPITAL_INCREASE) {
        p = 0;
    }
    cout << c << " " << p << endl;
    if (is_debug) {
        switch (card.type) {
            case CardType::NORMAL_WORK:
                projects[p].rest -= card.w;
                if (projects[p].is_completed()) {
                    money += projects[p].value;
                    projects[p] = debug_project_pop();
                }
                break;
            case CardType::FULL_POWER_WORK:
                for (auto& project : projects) {
                    project.rest -= card.w;
                    if (project.is_completed()) {
                        money += project.value;
                        project = debug_project_pop();
                    }
                }
                break;
            case CardType::CANCEL:
                projects[p] = debug_project_pop();
                break;
            case CardType::CONVERT:
                rep(i, M) { projects[i] = debug_project_pop(); }
                break;
            case CardType::CAPITAL_INCREASE:
                cap_inc_count++;
                break;
            default:
                break;
        }
    } else {
        rep(i, M) {
            int h, v;
            cin >> h >> v;
            projects[i] = {h, v};
        }
    }
    want_to_remove_count = 0;
    rep(i, M) {
        if (!projects[i].is_high_cospa()) want_to_remove_count++;
    }
}

void get_money() {
    if (!is_debug) {
        cin >> money;
    }
}

// カード候補の取得
vector<CardCandidate> get_candidates() {
    vector<CardCandidate> candidates(K);
    if (is_debug) {
        rep(i, K) { candidates[i] = debug_card_pop(); }
    } else {
        rep(i, K) {
            int t, w, p;
            cin >> t >> w >> p;
            candidates[i] = {static_cast<CardType>(t), w, p, (int)i};
        }
    }
    return candidates;
}

// カード候補の選択
int choose_card_cand(int c, vector<CardCandidate> candidates) {
    if (turn == 1000) {
        return 0;
    }
    if (turn < 1000 - 1000 / (cap_inc_count + 2) && cap_inc_count < 20) {
        int min_cost = 1e9, min_cost_index = -1;
        rep(i, K) {
            if (candidates[i].type == CardType::CAPITAL_INCREASE && candidates[i].p <= min(money * 23 / 32, 400 * pow(2, cap_inc_count)) &&
                chmin(min_cost, candidates[i].p)) {
                min_cost_index = i;
            }
        }
        if (min_cost_index != -1) {
            return min_cost_index;
        }
    }
    if (have_to_convert()) {
        int min_cost = 1e9, min_cost_index = -1;
        rep(i, K) {
            if (candidates[i].type == CardType::CONVERT && candidates[i].p <= money && chmin(min_cost, candidates[i].p)) {
                min_cost_index = i;
            }
        }
        if (min_cost_index != -1) {
            return min_cost_index;
        }
    }

    int r = 0;
    double max_cost_performance = 0;
    rep(i, K) {
        if (candidates[i].p <= money && chmax(max_cost_performance, candidates[i].cost_performance())) {
            r = i;
        }
    }
    if (max_cost_performance < p_w_cospa_threshold) {
        r = 0;
    }

    if (r == 0 && cards.cancel_idx() == -1) {
        rep(i, K) {
            if (candidates[i].type == CardType::CANCEL && candidates[i].p == 0) {
                return i;
            }
        }
    }

    if (N >= 3 && r == 0 && cards.convert_idx() == -1) {
        rep(i, K) {
            if (candidates[i].type == CardType::CONVERT && candidates[i].p == 0) {
                return i;
            }
        }
    }

    return r;
}

// カードの更新
void update_card(int c) {
    auto candidates = get_candidates();
    int r = choose_card_cand(c, candidates);
    cout << r << endl;
    cards[c] = candidates[r];
    money -= candidates[r].p;
}

int main() {
    init_in();

    while (T--) {
        turn++;
        auto [c, p] = choose_card();
        update_project(c, p);
        get_money();
        update_card(c);
        assert(money >= 0);
    }
    if (is_debug) {
        cerr << money << endl;
    }
}
