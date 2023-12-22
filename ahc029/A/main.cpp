#include "../../lib.hpp"

#if HASSAKU_DEBUG
#define is_debug true
#else
#define is_debug false
#endif

int N, M, K, T;
int money = 0;  // 所持金
int cap_inc_count = 0;
struct Project;
struct Card;
struct CardCandidate;
vector<Card> cards;                     // 手持ちのカード
vector<Project> projects;               // 進行中のプロジェクト
queue<Project> debug_projects;          // デバッグ用のプロジェクト
queue<CardCandidate> debug_candidates;  // デバッグ用のカード候補

enum class CardType { NORMAL_WORK, FULL_POWER_WORK, CANCEL, CONVERT, CAPITAL_INCREASE };

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
        }
    }
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
    // sort(all(candidates), [](const CardCandidate& a, const CardCandidate& b) { return a.cost_performance() > b.cost_performance(); });
    // CardCandidate cand;
    // while (cand = candidates.back(), cand.p > money) {
    //     candidates.pop_back();
    // }
    // int r = cand.id;
    int r = 0;
    cout << r << endl;
    return r;
}

// カードの更新
void update_card(int c) {
    auto candidates = get_candidates();
    int r = choose_card_cand(c, candidates);
    cards[c] = candidates[r];
    money -= candidates[r].p;
}

int main() {
    init_in();

    rep(turn, T) {
        double max_cost_performance = 0;
        int max_cost_performance_index = -1;
        rep(i, M) {
            if (chmax(max_cost_performance, projects[i].cost_performance())) {
                max_cost_performance_index = i;
            }
        }
        int max_performance_card_index = -1, max_performance_card = 0;
        rep(i, N) {
            if (chmax(max_performance_card, cards[i].performance())) {
                max_performance_card_index = i;
            }
        }
        int c = max_performance_card_index;
        update_project(c, max_cost_performance_index);
        get_money();
        update_card(c);
    }
}
