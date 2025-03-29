#ifndef HASSAKU_ROLLING_HASH
#define HASSAKU_ROLLING_HASH

#include <vector>

namespace hassaku {

template <int MOD, int BASE>
class RollingHash {
   public:
    RollingHash(const std::string& s) : n_(s.size()), hash_(n_ + 1, 0), power_(n_ + 1, 1) {
        for (int i = 0; i < n_; ++i) {
            hash_[i + 1] = (hash_[i] * BASE + s[i]) % MOD;
            power_[i + 1] = (power_[i] * BASE) % MOD;
        }
    }

    // [l, r) のハッシュ値を計算します (0-indexed)
    long long getHash(int l, int r) const {
        long long res = (hash_[r] - hash_[l] * power_[r - l]) % MOD;
        if (res < 0) res += MOD;
        return res;
    }

    RollingHash operator+(const RollingHash& rhs) const {
        RollingHash res = *this;
        res.hash_.resize(n_ + rhs.n_ + 1);
        res.power_.resize(n_ + rhs.n_ + 1);
        for (int i = 0; i < rhs.n_; ++i) {
            res.hash_[n_ + i + 1] = (res.hash_[n_ + i] * BASE + rhs.hash_[i]) % MOD;
            res.power_[n_ + i + 1] = (res.power_[n_ + i] * BASE) % MOD;
        }
        res.n_ += rhs.n_;
        return res;
    }

   private:
    int n_;
    std::vector<long long> hash_;
    std::vector<long long> power_;
};

}  // namespace hassaku

#endif