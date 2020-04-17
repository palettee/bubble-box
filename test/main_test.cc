#include <stdio.h>
#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

int main(int argc, char **argv) {
  testing::InitGoogleMock(&argc, argv);
  testing::GMOCK_FLAG(catch_leaked_mocks) = true;
  testing::GMOCK_FLAG(verbose) = "warning";
  return RUN_ALL_TESTS();
}
