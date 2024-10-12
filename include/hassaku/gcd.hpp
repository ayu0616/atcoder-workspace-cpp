#ifndef HASSAKU_GCD_HPP
#define HASSAKU_GCD_HPP

namespace hassaku {

template <typename T>
T extgcd(T a, T b, T &x, T &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

}  // namespace hassaku

#endif