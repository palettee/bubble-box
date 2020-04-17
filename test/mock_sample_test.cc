#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <stdio.h>
#include <string>

using testing::_;
using testing::Return;
using testing::NaggyMock;

class MockFoo {
    public:
     MockFoo() {}

     MOCK_METHOD3(Bar, char(const std::string& s, int i, double x));
     MOCK_METHOD2(Bar2, bool(int x, int y));

    private:
     GTEST_DISALLOW_COPY_AND_ASSIGN_(MockFoo);
};

class GMockOutputTest : public testing::Test {
    protected:
     NaggyMock<MockFoo> foo_;
};

TEST_F(GMockOutputTest, ExpectedCall) {
    testing::GMOCK_FLAG(verbose) = "info";

    EXPECT_CALL(foo_, Bar2(0, _));
    foo_.Bar2(0, 0);

    testing::GMOCK_FLAG(verbose) = "warning";
}

TEST_F(GMockOutputTest, ExplicitActionsRunOut) {
  EXPECT_CALL(foo_, Bar2(_, _))
      .Times(2)
      .WillOnce(Return(false));
  foo_.Bar2(2, 2);
  foo_.Bar2(1, 1);  // Explicit actions in EXPECT_CALL run out.
}