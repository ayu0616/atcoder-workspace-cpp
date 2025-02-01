#ifndef HASSAKU_GCD_HPP
#define HASSAKU_GCD_HPP

#include <tuple>

namespace hassaku {

template <typename T>
std::pair<T, T> extgcd(T a, T b) {
    if (b == 0) return std::make_pair(1, 0);
    long long x, y;
    std::tie(y, x) = extgcd(b, a % b);
    y -= a / b * x;
    return std::make_pair(x, y);
}

}  // namespace hassaku

#endif