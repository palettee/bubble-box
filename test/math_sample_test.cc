#include <gtest/gtest.h>

#include "math_sample.h"

TEST(math_sample_test, factorial_test) {
    EXPECT_EQ( 2, factorial(2));
    EXPECT_EQ( 6, factorial(3));
    EXPECT_EQ( 24, factorial(4));
    EXPECT_EQ( 120, factorial(5));
}

TEST(math_sample_test, prime_test) {
    EXPECT_EQ( true, isPrime(3, 2));
    EXPECT_EQ( true, isPrime(5, 2));
    EXPECT_EQ( true, isPrime(7, 2));
}