#include <bits/stdc++.h>
#include <atcoder/fenwicktree>

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);  // 入出力の高速化
    cin.tie(nullptr);             // 入出力の同期を解除

    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for (ll &a : A) cin >> a;

    // 累積和 S の計算
    vector<ll> S(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        S[i + 1] = S[i] + A[i];
    }

    // S mod M とその累積和の計算
    vector<ll> ModS(N + 1, 0);
    vector<ll> PrefixModSum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        ModS[i] = S[i] % M;
        PrefixModSum[i] = PrefixModSum[i - 1] + ModS[i];
    }

    // Fenwick Tree の初期化
    fenwick_tree<ll> ft(M);
    ft.add(ModS[0], 1);  // 初期値としてModS[0]を追加

    // Total の計算
    ll total = 0;
    for (int r = 1; r <= N; ++r) {
        // ModS[r] の値より大きい ModS[i] の数を取得
        int count = ft.sum(ModS[r] + 1, M);
        total += ModS[r] * r - PrefixModSum[r - 1] + (ll)M * count;
        ft.add(ModS[r], 1);
    }

    cout << total << "\n";
    return 0;
}