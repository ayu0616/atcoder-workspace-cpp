// TODO: コンパイルが通るように修正

#include "hassaku/cumulative-sum.hpp"

#include <gtest/gtest.h>

#include <vector>

TEST(TestCase, TestName) {
    std::vector<int> v = {1, 2, 3, 4, 5};
    hassaku::CumulativeSum1D<int> cs(v);
    ASSERT_EQ(cs.get(0, 3), 6);
    ASSERT_EQ(cs.get(1, 4), 9);
    ASSERT_EQ(cs.get(2, 5), 12);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}