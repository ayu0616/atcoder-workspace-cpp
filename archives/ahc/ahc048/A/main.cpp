#include <bits/stdc++.h>

#include <queue>
#include <vector>

using namespace std;

struct Color {
    double C, M, Y;

    Color(double C, double M, double Y) : C(C), M(M), Y(Y) {}

    double diff(Color other) const { return sqrt(pow(C - other.C, 2) + pow(M - other.M, 2) + pow(Y - other.Y, 2)); }
};

struct Input {
    int N, K, H, T, D;
    vector<Color> C_own;
    vector<Color> C_target;

    static Input read() {
        Input in;
        cin >> in.N >> in.K >> in.H >> in.T >> in.D;
        for (int i = 0; i < in.K; i++) {
            double C, M, Y;
            cin >> C >> M >> Y;
            in.C_own.push_back({C, M, Y});
        }
        for (int i = 0; i < in.H; i++) {
            double C, M, Y;
            cin >> C >> M >> Y;
            in.C_target.push_back({C, M, Y});
        }
        return in;
    }
};

struct Operation {
    virtual void apply() = 0;
    Operation() {}
};
struct AddOperation : Operation {
    int i, j, k;
    AddOperation(int i, int j, int k) : i(i), j(j), k(k) {}
    void apply() override { cout << 1 << " " << i << " " << j << " " << k << endl; }
};
struct ExtractOperation : Operation {
    int i, j;
    ExtractOperation(int i, int j) : i(i), j(j) {}
    void apply() override { cout << 2 << " " << i << " " << j << endl; }
};
struct DiscardOperation : Operation {
    int i, j;
    DiscardOperation(int i, int j) : i(i), j(j) {}
    void apply() override { cout << 3 << " " << i << " " << j << endl; }
};
struct ToggleDividerOperation : Operation {
    int i1, j1, i2, j2;
    ToggleDividerOperation(int i1, int j1, int i2, int j2) : i1(i1), j1(j1), i2(i2), j2(j2) {}
    void apply() override { cout << 4 << " " << i1 << " " << j1 << " " << i2 << " " << j2 << endl; }
};

int main() {
    Input in = Input::read();
    vector<vector<int>> v(in.N, vector<int>(in.N - 1, 0)), h(in.N - 1, vector<int>(in.N, 1));
    for (int i = 0; i < in.N; i++) {
        for (int j = 1; j < in.N - 1; j += 2) {
            v[i][j] = 1;
        }
    }
    for (int i = 0; i < in.N; i++) {
        for (int j = 0; j < in.N - 1; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < in.N - 1; i++) {
        for (int j = 0; j < in.N; j++) {
            cout << h[i][j] << " ";
        }
        cout << endl;
    }
    priority_queue<pair<double, int>> pq;
    vector<vector<Operation*>> operations(in.H);
    for (int i = 0; i < in.H; i++) {
        int best_k = -1;
        double best_diff = 1e9;
        Color target = in.C_target[i];
        for (int k = 0; k < in.K; k++) {
            double diff = in.C_own[k].diff(target);
            if (diff < best_diff) {
                best_diff = diff;
                best_k = k;
            }
        }
        operations[i].push_back(new AddOperation(0, 0, best_k));
        operations[i].push_back(new ExtractOperation(0, 0));
        pq.push({best_diff, i});
    }
    int cnt = 2 * in.H;
    while (!pq.empty()) {
        if (cnt > in.T) break;
        auto [diff, i] = pq.top();
        pq.pop();
        pair<int, int> best_k = {-1, -1};
        double best_diff = 1e9;
        for (int k1 = 0; k1 < in.K; k1++) {
            for (int k2 = 0; k2 < in.K; k2++) {
                if (k1 == k2) continue;
                Color c = Color((in.C_own[k1].C + in.C_own[k2].C) / 2, (in.C_own[k1].M + in.C_own[k2].M) / 2, (in.C_own[k1].Y + in.C_own[k2].Y) / 2);
                double diff = c.diff(in.C_target[i]);
                if (diff < best_diff) {
                    best_diff = diff;
                    best_k = {k1, k2};
                }
            }
        }
        if (round(diff * 10000) < round(best_diff * 10000) + in.D) {
            continue;
        }
        vector<Operation*> ops;
        ops.push_back(new AddOperation(0, 0, best_k.first));
        ops.push_back(new AddOperation(0, 0, best_k.second));
        ops.push_back(new ExtractOperation(0, 0));
        ops.push_back(new DiscardOperation(0, 0));
        int cnt_diff = ops.size() - operations[i].size();
        if (cnt + cnt_diff > in.T) {
            break;
        }
        operations[i] = ops;
        cnt += cnt_diff;
    }
    for (auto ops : operations) {
        for (auto op : ops) {
            op->apply();
        }
    }
    return 0;
}
