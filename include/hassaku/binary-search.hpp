// 二分探索のライブラリ

#ifndef HASSAKU_BINARY_SEARCH
#define HASSAKU_BINARY_SEARCH

#include <functional>
using namespace std;

namespace hassaku {

template <typename T>
T binary_search(T ok, T ng, function<bool(T)> is_ok, T eps = 1) {
    while (abs(ok - ng) > eps) {
        T mid = (ok + ng) / 2;
        if (is_ok(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

}  // namespace hassaku

#endif