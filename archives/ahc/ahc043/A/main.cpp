#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <functional>
#include <iostream>
#include <vector>

#include "./state.cpp"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

vector<vector<TrackType>> inline create_initial_tracks(int N, vector<Citizen> citizens, int K) {
    double home_i_sum = 0.0, home_j_sum = 0.0, work_i_sum = 0.0, work_j_sum = 0.0;
    for (auto c : citizens) {
        home_i_sum += c.home.i;
        home_j_sum += c.home.j;
        work_i_sum += c.work.i;
        work_j_sum += c.work.j;
    }
    District home_center = {(int)(home_i_sum / citizens.size()), (int)(home_j_sum / citizens.size())};
    District work_center = {(int)(work_i_sum / citizens.size()), (int)(work_j_sum / citizens.size())};
    int min_dist_index = 0;
    double min_sum_dist = 1e18;

    for (int i = 0; i < citizens.size(); ++i) {
        double home_dist = abs(citizens[i].home.i - home_center.i) + abs(citizens[i].home.j - home_center.j);
        double work_dist = abs(citizens[i].work.i - work_center.i) + abs(citizens[i].work.j - work_center.j);

        int d = abs(citizens[i].home.i - citizens[i].work.i) + abs(citizens[i].home.j - citizens[i].work.j);

        if (home_dist + work_dist < min_sum_dist && d * 100 <= K - 10000) {
            min_sum_dist = home_dist + work_dist;
            min_dist_index = i;
        }
    }

    vector<vector<TrackType>> tracks(N, vector<TrackType>(N, TrackType::NONE));
    tracks[citizens[min_dist_index].home.i][citizens[min_dist_index].home.j] = TrackType::STATION;
    tracks[citizens[min_dist_index].work.i][citizens[min_dist_index].work.j] = TrackType::STATION;
    District start = citizens[min_dist_index].home;
    District end = citizens[min_dist_index].work;

    function<void(District, District)> build_path = [&](District s, District e) {
        // 現在位置をスタート地点に設定
        int ci = s.i, cj = s.j;

        // X方向の差分を計算
        int dx = e.i - ci;
        if (dx != 0) {
            int step = dx > 0 ? 1 : -1;
            // X方向に移動しながら線路を敷設
            for (int k = 0; k < abs(dx); k++) {
                if (tracks[ci][cj] == TrackType::NONE) {
                    tracks[ci][cj] = TrackType::TB;
                }
                ci += step;
            }
        }

        // Y方向の差分を計算
        int dy = e.j - cj;
        if (dy != 0) {
            int step = dy > 0 ? 1 : -1;
            // Y方向に移動しながら線路を敷設
            for (int k = 0; k < abs(dy); k++) {
                if (tracks[ci][cj] == TrackType::NONE) {
                    tracks[ci][cj] = TrackType::LR;
                }
                cj += step;
            }
        }

        // 曲がり角の調整（X方向とY方向の両方に移動があった場合）
        if (dx != 0 && dy != 0) {
            // 進行方向に基づいて曲がり角のタイプを決定
            const int di = (dx > 0) ? 1 : -1;  // X方向の進行方向
            const int dj = (dy > 0) ? 1 : -1;  // Y方向の進行方向

            // 曲がり角の座標（X移動終了点）
            const int turn_i = s.i + dx;
            const int turn_j = s.j;

            // 進行方向の組み合わせで接続タイプを決定
            if (di == 1 && dj == 1) tracks[turn_i][turn_j] = TrackType::LB;    // 下→右
            if (di == 1 && dj == -1) tracks[turn_i][turn_j] = TrackType::LT;   // 下→左
            if (di == -1 && dj == 1) tracks[turn_i][turn_j] = TrackType::RB;   // 上→右
            if (di == -1 && dj == -1) tracks[turn_i][turn_j] = TrackType::RT;  // 上→左
        }
    };
    build_path(start, end);
    return tracks;
}

int main() {
    int N, M, K, T;
    cin >> N >> M >> K >> T;
    vector<Citizen> citizens(M);
    rep(i, M) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        citizens[i] = Citizen{{a, b}, {c, d}};
    }

    State root = State{K, T, 0, {}, vector(N, vector(N, TrackType::NONE)), {}};
    vector<State> states = {};
    rep(i,N)rep(j, N){
        State state = root;
        state.grid[i][j] = TrackType::STATION;
        state.turn--;
        state.money -= 5000;
        state.stations.push_back(Station(i, j, citizens));
        state.operations.push_back(Operation{TrackType::STATION, {i, j}});
        states.push_back(state);
    }

    vector<Operation> operations;
    for (auto op : operations) {
        op.print();
    }
    for (int i = operations.size(); i < T; i++) {
        cout << -1 << endl;
    }
    return 0;
}
