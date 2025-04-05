#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

#include <algorithm>
#include <cmath>  // For std::abs
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

// --- Assuming necessary type aliases and macros like rep ---
using ll = long long;
using pll = std::pair<ll, ll>;
using vl = std::vector<ll>;
using vb = std::vector<bool>;
using vvl = std::vector<vl>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
// --- End Assuming ---

// Function to check if a specific swap works for pair (a, b)
bool check_swap(ll swap_a_idx, ll swap_b_idx, ll other_a_idx, ll other_b_idx) {
    // After swap: a is at swap_b_idx, b is at swap_a_idx
    // Check if the other 'a' (at other_a_idx) is adjacent to the new 'a' (at swap_b_idx)
    bool a_adj = (std::abs(other_a_idx - swap_b_idx) == 1);
    // Check if the other 'b' (at other_b_idx) is adjacent to the new 'b' (at swap_a_idx)
    bool b_adj = (std::abs(other_b_idx - swap_a_idx) == 1);
    return a_adj && b_adj;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout << std::fixed << std::setprecision(18);

    ll T;
    std::cin >> T;
    while (T--) {
        ll N;
        std::cin >> N;
        vl A(2 * N);
        vvl pos(N);  // Store positions for each number
        rep(i, 2 * N) {
            std::cin >> A[i];
            A[i]--;                      // 0-indexed
            if (pos[A[i]].size() < 2) {  // Ensure we only store the first two positions
                pos[A[i]].push_back(i);
            }
        }

        vb is_ok(N, true);  // Check for adjacent identical elements
        rep(i, 2 * N - 1) {
            if (A[i] == A[i + 1]) {
                is_ok[A[i]] = false;
            }
        }

        ll count = 0;
        // Iterate through all pairs (a, b) such that 0 <= a < b < N
        for (ll a = 0; a < N; ++a) {
            if (!is_ok[a]) continue;  // Skip if 'a' is adjacent
            // Ensure pos[a] is valid (should always have 2 elements by constraints)
            if (pos[a].size() != 2) continue;

            for (ll b = a + 1; b < N; ++b) {
                if (!is_ok[b])
                    continue;  // Skip if 'b' is adjacent
                               // Ensure pos[b] is valid
                if (pos[b].size() != 2) continue;

                ll p_a1 = pos[a][0];
                ll p_a2 = pos[a][1];
                ll p_b1 = pos[b][0];
                ll p_b2 = pos[b][1];

                bool possible = false;
                // Check the 4 possible swaps
                if (check_swap(p_a1, p_b1, p_a2, p_b2)) possible = true;
                if (!possible && check_swap(p_a1, p_b2, p_a2, p_b1)) possible = true;
                if (!possible && check_swap(p_a2, p_b1, p_a1, p_b2)) possible = true;
                if (!possible && check_swap(p_a2, p_b2, p_a1, p_b1)) possible = true;

                if (possible) {
                    count++;
                }
            }
        }
        std::cout << count << "\n";
    }
    return 0;
}
