#include <gtest/gtest.h>

TEST(MathTests, Addition) {
    EXPECT_EQ(2 + 2, 4);
}

TEST(MathTests, Subtraction) {
    ASSERT_GT(10 - 5, 0);
}