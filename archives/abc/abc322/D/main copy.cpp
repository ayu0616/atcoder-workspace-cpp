#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Polyomino {
    vpii pos;
    int H, W;
};

int main() {
    vs _P1(4), _P2(4), _P3(4);
    cin >> _P1 >> _P2 >> _P3;
    Polyomino P1, P2, P3;
    int min_h = 4, max_h = 0, min_w = 4, max_w = 0;
    vpii pos;
    rep(i, 4) rep(j, 4) {
        if (_P1[i][j] == '#') {
            pos.emplace_back(i, j);
            chmin(min_h, (int)i);
            chmax(max_h, (int)i);
            chmin(min_w, (int)j);
            chmax(max_w, (int)j);
        }
    }
    P1.H = max_h - min_h + 1;
    P1.W = max_w - min_w + 1;
    for (auto [i, j] : pos) {
        P1.pos.emplace_back(i - min_h, j - min_w);
    }
    min_h = 4, max_h = 0, min_w = 4, max_w = 0;
    pos.clear();
    rep(i, 4) rep(j, 4) {
        if (_P2[i][j] == '#') {
            P2.pos.emplace_back(i, j);
            chmin(min_h, (int)i);
            chmax(max_h, (int)i);
            chmin(min_w, (int)j);
            chmax(max_w, (int)j);
        }
    }
    P2.H = max_h - min_h + 1;
    P2.W = max_w - min_w + 1;
    for (auto [i, j] : pos) {
        P2.pos.emplace_back(i - min_h, j - min_w);
    }
    min_h = 4, max_h = 0, min_w = 4, max_w = 0;
    rep(i, 4) rep(j, 4) {
        if (_P3[i][j] == '#') {
            P3.pos.emplace_back(i, j);
            chmin(min_h, (int)i);
            chmax(max_h, (int)i);
            chmin(min_w, (int)j);
            chmax(max_w, (int)j);
        }
    }
    P3.H = max_h - min_h + 1;
    P3.W = max_w - min_w + 1;
    for (auto [i, j] : pos) {
        P3.pos.emplace_back(i - min_h, j - min_w);
    }
}
