// 累積和のライブラリ

#ifndef HASSAKU_CUMULATIVE_SUM
#define HASSAKU_CUMULATIVE_SUM

#include <vector>

namespace hassaku {

template <typename T>
class CumulativeSum1D {
   private:
    std::vector<T> sum;

   public:
    CumulativeSum1D(const std::vector<T> &v) {
        int n = v.size();
        sum.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = v[i] + sum[i];
        }
    }

    T get(int l, int r) { return sum[r] - sum[l]; }
};

template <typename T>
class CumulativeSum2D {
   private:
    std::vector<std::vector<T>> sum;

   public:
    CumulativeSum2D(const std::vector<std::vector<T>> &v) {
        int h = v.size();
        int w = v[0].size();
        sum.assign(h + 1, std::vector<T>(w + 1, 0));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                sum[i + 1][j + 1] = v[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
            }
        }
    }

    T get(int x1, int y1, int x2, int y2) { return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1]; }
};

template <typename T>
class CumulativeSum3D {
   private:
    std::vector<std::vector<std::vector<T>>> sum;

   public:
    CumulativeSum3D(const std::vector<std::vector<std::vector<T>>> &v) {
        int x = v.size();
        int y = v[0].size();
        int z = v[0][0].size();
        sum.assign(x + 1, std::vector<std::vector<T>>(y + 1, std::vector<T>(z + 1, 0)));
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                for (int k = 0; k < z; k++) {
                    sum[i + 1][j + 1][k + 1] = v[i][j][k] + sum[i + 1][j][k] + sum[i][j + 1][k] + sum[i][j][k + 1] - sum[i + 1][j + 1][k] -
                                               sum[i + 1][j][k + 1] - sum[i][j + 1][k + 1] + sum[i][j][k];
                }
            }
        }
    }

    T get(int x1, int y1, int z1, int x2, int y2, int z2) {
        return sum[x2][y2][z2] - sum[x1][y2][z2] - sum[x2][y1][z2] - sum[x2][y2][z1] + sum[x1][y1][z2] + sum[x1][y2][z1] + sum[x2][y1][z1] - sum[x1][y1][z1];
    }
};
}  // namespace hassaku

#endif