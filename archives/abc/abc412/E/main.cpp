#include "hassaku/prime.hpp"
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

uint64_t modmul(uint64_t a, uint64_t b, uint64_t n) { return (uint64_t)(((__uint128_t)a) * ((__uint128_t)b) % ((__uint128_t)n)); }
uint64_t modpow(uint64_t a, uint64_t b, uint64_t n) {
    uint64_t t = ((b & 1) == 0) ? 1 : a;
    for (b >>= 1; b != 0; b >>= 1) {
        a = modmul(a, a, n);
        if ((b & 1) == 1) {
            t = modmul(t, a, n);
        }
    }
    return t;
}
constexpr uint64_t bases[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
bool is_prime(uint64_t n) {
    if (n == 2) {
        return true;
    }
    if (n < 2 || (n & 1) == 0) {
        return false;
    }
    uint64_t n1 = n - 1, d = n - 1;
    uint32_t s = 0;
    for (; (d & 1) == 0; d >>= 1) {
        s += 1;
    }
    for (const auto& base : bases) {
        uint64_t a = base;
        if (a >= n) {
            a %= n;
            if (a == 0) {
                continue;
            }
        }
        uint64_t t = modpow(a, d, n);
        if (t == 1) {
            continue;
        }
        for (uint32_t j = 1; t != n1; ++j) {
            if (j >= s) {
                return false;
            }
            t = modmul(t, t, n);
        }
    }
    return true;
}

int main() {
    cout << fixed << setprecision(18);
    ll L, R;
    cin >> L >> R;
    auto primes = hassaku::create_primes(10000000);
    ll ans = 1;
    for (ll p : primes) {
        for (ll pp = p; pp <= R; pp *= p) {
            if (L < pp && pp <= R) {
                ans++;
            }
        }
    }
    if (R >= 10000000) {
        for (ll x = max(L + 1 + (L & 1), 10000001); x <= R; x += 2) {
            if (is_prime(x)) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
