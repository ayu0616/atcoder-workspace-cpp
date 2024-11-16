#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N, M, L;

map<tuple<vl, vl, vl, int>, bool> memo;
bool play(vl A, vl B, vl C, int turn) {
    sort(all(A));
    sort(all(B));
    sort(all(C));
    if (memo.count({A, B, C, turn % 2})) return memo[{A, B, C, turn % 2}];
    if (turn % 2 == 0) {
        if (A.empty()) return false;
        rep(i, A.size()) {
            ll a = A[i];
            vl new_A = A;
            new_A.erase(new_A.begin() + i);
            rep(j, C.size()) {
                vl new_A_cp = new_A;
                ll c = C[j];
                vl new_C = C;
                if (c < a) {
                    new_C.erase(new_C.begin() + j);
                    new_A_cp.push_back(c);
                }
                new_C.push_back(a);
                if (play(new_A_cp, B, new_C, turn + 1)) return memo[{A, B, C, turn % 2}] = true;
            }
        }
        return memo[{A, B, C, turn % 2}] = false;
    } else {
        if (B.empty()) return true;
        rep(i, B.size()) {
            ll b = B[i];
            vl new_B = B;
            new_B.erase(new_B.begin() + i);
            rep(j, C.size()) {
                vl new_B_cp = new_B;
                ll c = C[j];
                vl new_C = C;
                if (c < b) {
                    new_C.erase(new_C.begin() + j);
                    new_B_cp.push_back(c);
                }
                new_C.push_back(b);
                if (!play(A, new_B_cp, new_C, turn + 1)) return memo[{A, B, C, turn % 2}] = false;
            }
        }
        return memo[{A, B, C, turn % 2}] = true;
    }
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> M >> L;
    vl A(N), B(M), C(L);
    cin >> A >> B >> C;
    if (play(A, B, C, 0)) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
