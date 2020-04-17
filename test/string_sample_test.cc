#include "gtest/gtest.h"
#include "string_sample.h"

namespace {


TEST(MyString, DefaultConstructor) {
    const MyString s;

    EXPECT_STREQ(NULL, s.c_string());
    EXPECT_EQ(0u, s.Length());
}

TEST(MyString, constructor_from_cstring) {
    const char sHelloWorld[] = "hello world";
    const MyString s(sHelloWorld);

    EXPECT_STREQ(sHelloWorld, s.c_string());
    EXPECT_EQ(sizeof(sHelloWorld)/sizeof(sHelloWorld[0]) - 1, s.Length());
}

TEST(MyString, copy_constructor) {
    const char sHelloWorld[] = "hello world";
    const MyString s(sHelloWorld);
    const MyString copied = s;
    EXPECT_STREQ(sHelloWorld, copied.c_string());
}

TEST(MyString, Set_function) {
    const char sHelloWorld[] = "hello world";
    MyString s;
    s.Set(NULL);
    EXPECT_EQ(NULL, s.c_string());

    s.Set(sHelloWorld);
    EXPECT_STREQ(sHelloWorld, s.c_string());

    s.Set(s.c_string());
    EXPECT_STREQ(sHelloWorld, s.c_string());
}

}