#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N;
string S, T;
vector<map<char, int>> s_cnt;

ll char_cnt(char c, ll from, ll to) {
    ll from_idx = from % S.size();
    ll to_idx = to % S.size();
    ll from_s_idx = from / S.size();
    ll to_s_idx = to / S.size();
    ll res = s_cnt.back()[c] * to_s_idx + s_cnt[to_idx+1][c];
    res -= s_cnt.back()[c] * from_s_idx + s_cnt[from_idx][c];
    return res;
}

// from以降でtiがk個目に出現する位置を返す
ll get_ti(ll from, char ti, ll k) {
    ll len = N * S.size();
    ll l = from, r = len;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (char_cnt(ti, from, m) >= k) {
            r = m;
        } else {
            l = m;
        }
    }
    if (char_cnt(ti, 0, l) == k) {
        return l;
    }
    return -1;
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> S >> T;
    s_cnt.resize(S.size() + 1);
    rep(i, S.size()) {
        s_cnt[i + 1] = s_cnt[i];
        s_cnt[i + 1][S[i]]++;
    }
    ll l = 0, r = N * S.size();
    while (r - l > 1) {
        ll m = (l + r) / 2;
        bool ok = true;
        ll from = 0;
        rep(i, T.size()) {
            ll to = get_ti(from, T[i], m);
            if (to == -1) {
                ok = false;
                break;
            }
            from = to + 1;
        }
        if (ok) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;
}
