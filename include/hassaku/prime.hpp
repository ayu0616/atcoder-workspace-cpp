#ifndef HASSAKU_PRIME_HPP
#define HASSAKU_PRIME_HPP

#include <vector>

using ll = long long;
using vl = std::vector<ll>;

namespace hassaku {

/* 素数判定 */
constexpr bool is_prime(const ll n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

/*
@brief 素数を列挙する関数
@param upper 素数の上限
 */
inline std::vector<ll> create_primes(const ll upper) {
    std::vector<ll> primes;
    std::vector<bool> is_p(upper + 1, true);

    for (ll i = 2; i <= upper; i++) {
        if (is_p[i]) {
            primes.push_back(i);
            for (ll j = i * 2; j <= upper; j += i) {
                is_p[j] = false;
            }
        }
    }
    return primes;
}

/* @brief 素因数分解 */
template <class T>
constexpr vl prime_factorize(const T n) {
    vl res;
    while (n % 2 == 0) {
        res.emplace_back(2);
        n /= 2;
    }
    for (T i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            res.emplace_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.emplace_back(n);
    }
    return res;
}

}  // namespace hassaku

#endif