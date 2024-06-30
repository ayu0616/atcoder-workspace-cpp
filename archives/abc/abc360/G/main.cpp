#include <cassert>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

/// @brief 最長増加部分列（LIS）のインデックスを返します
/// @tparam Strict 狭義単調増加の場合 true, 広義単調増加の場合 false
/// @tparam Type 数列の要素の型
/// @param v 数列
/// @return 最長増加部分列（LIS）のインデックス
/// @note 1.4 最長増加部分列の復元
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/lis
template <bool Strict, class Type>
std::vector<int> LIS(const std::vector<Type>& v) {
    std::vector<Type> dp;

    auto it = dp.begin();

    std::vector<int> positions;

    for (const auto& elem : v) {
        if constexpr (Strict) {
            it = std::lower_bound(dp.begin(), dp.end(), elem);
        } else {
            it = std::upper_bound(dp.begin(), dp.end(), elem);
        }

        positions.push_back(static_cast<int>(it - dp.begin()));

        if (it == dp.end()) {
            dp.push_back(elem);
        } else {
            *it = elem;
        }
    }

    std::vector<int> subseq(dp.size());

    int si = static_cast<int>(subseq.size()) - 1;

    int pi = static_cast<int>(positions.size()) - 1;

    while ((0 <= si) && (0 <= pi)) {
        if (positions[pi] == si) {
            subseq[si] = pi;

            --si;
        }

        --pi;
    }

    return subseq;
}

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    vi res = LIS<true>(A);
    if (res.size() == N) {
        cout << N << endl;
        return 0;
    }
    if (res[0] != 0 && A[res[0]] >= 2) {
        cout << res.size() + 1 << endl;
        return 0;
    }
    if (res.back() != N - 1 && A[res.back()] < N) {
        cout << res.size() + 1 << endl;
        return 0;
    }
    bool ok = false;
    rep(i, res.size() - 1) {
        if (res[i + 1] - res[i] > 1 && A[res[i + 1]] - A[res[i]] > 1) {
            ok = true;
            break;
        }
    }
    if (ok) {
        cout << res.size() + 1 << endl;
        return 0;
    }
    cout << res.size() << endl;
}
