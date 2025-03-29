#include <iostream>
#include <vector>

using namespace std;

struct District {
    int i, j;
};

struct Citizen {
    District home, work;
};

enum TrackType { STATION = 0, LR = 1, TB = 2, LB = 3, LT = 4, RT = 5, RB = 6, NONE = 99 };

vector<pair<int, int>> get_dxdy(TrackType type) {
    switch (type) {
        case TrackType::LR:
            return {{0, -1}, {0, 1}};
        case TrackType::TB:
            return {{-1, 0}, {1, 0}};
        case TrackType::LB:
            return {{-1, 0}, {0, -1}};
        case TrackType::LT:
            return {{-1, 0}, {0, 1}};
        case TrackType::RT:
            return {{1, 0}, {0, 1}};
        case TrackType::RB:
            return {{1, 0}, {0, -1}};
        case TrackType::STATION:
            return {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        case TrackType::NONE:
            return {{0, 0}};
        default:
            return {{0, 0}};
    }
}

struct Station {
    int i, j;
    vector<int> homes, works;

    Station(int i, int j, const vector<Citizen>& citizens) {
        this->i = i;
        this->j = j;
        for (auto c : citizens) {
            if (abs(c.home.i - i) + abs(c.home.j - j) <= 2) {
                homes.push_back(1);
            }
            if (abs(c.work.i - i) + abs(c.work.j - j) <= 2) {
                works.push_back(1);
            }
        }
    }
};

struct Operation {
    TrackType type;
    District d;
    bool is_wait = false;

    void inline print() const {
        if (is_wait) {
            cout << -1 << endl;
            return;
        }
        cout << type << " " << d.i << " " << d.j << endl;
    }
};

vector<pair<int, int>> const dij1 = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int>> const dij2 = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}, {2, 0}, {0, 2}, {-2, 0}, {0, -2}};

struct State {
    int money;
    // 残りターン数
    int turn;
    int income;
    vector<Station> stations;
    vector<vector<TrackType>> grid;
    vector<Operation> operations;

    inline int score() const { return money + income * turn; }

    inline void lay_tracks(int i, int j) {
        for (auto [di, dj] : dij2) {
            if (grid[i + di][j + dj] == TrackType::STATION) {
                return;
            }
        }
        for (auto [di, dj] : dij2) {
            if (grid[i + di][j + dj] != TrackType::NONE) {
                if (money >= 5000) {
                    money -= 5000;
                    turn -= 1;
                    Station st = Station(i + di, j + dj, {});  // TODO: citizens
                    stations.push_back(st);
                    grid[i + di][j + dj] = TrackType::STATION;
                    operations.push_back(Operation{TrackType::STATION, {i + di, j + dj}, false});
                } else {
                    int t = (5000 - money) / income;
                    while (t * income + money < 5000) t++;
                    turn -= t;
                    money += t * income;
                    for (int i = 0; i < t; i++) operations.push_back(Operation{TrackType::NONE, {i + di, j + dj}, true});
                    money -= 5000;
                    turn -= 1;
                    Station st = Station(i + di, j + dj, {});  // TODO: citizens
                    stations.push_back(st);
                    grid[i + di][j + dj] = TrackType::STATION;
                    operations.push_back(Operation{TrackType::STATION, {i + di, j + dj}, false});
                }
                return;
            }
        }
        vector<vector<pair<int, int>>> prev(grid.size(), vector<pair<int, int>>(grid[0].size(), {-1, -1}));
        vector<vector<int>> dist(grid.size(), vector<int>(grid[0].size(), -1));
        queue<pair<int, int>> q;

        dist[i][j] = 0;
        q.emplace(i, j);
    }

    inline vector<State> search(const int depth, const vector<Citizen>& citizens) const {
        const int N = grid.size();
        vector<State> nexts;
        for (auto citizen : citizens) {
            bool is_home = false, is_work = false;
            for (auto station : stations) {
                is_home |= abs(citizen.home.i - station.i) + abs(citizen.home.j - station.j) <= 2;
                is_work |= abs(citizen.work.i - station.i) + abs(citizen.work.j - station.j) <= 2;
            }
            if (is_home && is_work) continue;

            if (is_home) {
                int wx = citizen.work.i, wy = citizen.work.j;

                // 仕事場からのマンハッタン距離2以内の全位置をチェック
                for (int dx = -2; dx <= 2; ++dx) {
                    for (int dy = -2 + abs(dx); dy <= 2 - abs(dx); ++dy) {
                        State next = *this;
                        int nx = wx + dx;
                        int ny = wy + dy;

                        // グリッド範囲内かチェック（Nはグリッドサイズ）
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                            // この位置に駅を設置する処理
                            // （add_stationは駅を追加するメソッドの想定）
                            next.lay_tracks(nx, ny);
                        }
                        nexts.push_back(next);
                    }
                }
            } else if (is_work) {
            } else {
            }
        }
        return nexts;
    }

    inline bool operator<(const State& other) const { return score() < other.score(); }
};