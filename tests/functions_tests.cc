#include <gtest/gtest.h>

#include <function/function.h>

using namespace function;

TEST(FunctionTests, Fack_CreateValue1) {

    Function s(Type::fack);
    int ans = s.create_fun(3);
    EXPECT_EQ(ans, 6);

}

TEST(FunctionTests, Fack_CreateValue2) {

    Function s(Type::fack);
    int ans = s.create_fun(0);
    EXPECT_EQ(ans, 1);

}

TEST(FunctionTests, Fack_CreateValue3) {

    Function s(Type::fack);
    int ans = s.create_fun(4);
    EXPECT_EQ(ans, 24);

}

TEST(FunctionTests, Fack_CreateValue4) {

    Function s(Type::fack);
    int ans = s.create_fun(5);
    EXPECT_EQ(ans, 120);

}

TEST(FunctionTests, Fack_CreateValue5) {

    Function s(Type::fack);
    int ans = s.create_fun(1);
    EXPECT_EQ(ans, 1);

}

TEST(FunctionTests, Sqrc_CreateValue1) {
    Function s(Type::sqrc, 3);
    int ans1 = s.create_fun(1);
    int ans2 = s.create_fun(4);
    int ans3 = s.create_fun(5);

    EXPECT_EQ(ans1, 4);
    EXPECT_EQ(ans2, 19);
    EXPECT_EQ(ans3, 28);
}

TEST(FunctionTests, Sqrc_CreateValue2) {
    Function s(Type::sqrc, 0);
    int ans1 = s.create_fun(2);
    int ans2 = s.create_fun(7);
    int ans3 = s.create_fun(10);

    EXPECT_EQ(ans1, 4);
    EXPECT_EQ(ans2, 49);
    EXPECT_EQ(ans3, 100);
}

TEST(FunctionTests, Sqrc_CreateValue3) {
    Function s(Type::sqrc, -4);
    int ans1 = s.create_fun(3);
    int ans2 = s.create_fun(6);
    int ans3 = s.create_fun(9);

    EXPECT_EQ(ans1, 5);
    EXPECT_EQ(ans2, 32);
    EXPECT_EQ(ans3, 77);
}

TEST(FunctionTests, Sqrc_CreateValueSetShift1) {
    Function s(Type::sqrc, 5);
    s.set_c(4);

    int ans1 = s.create_fun(1);
    int ans2 = s.create_fun(4);
    int ans3 = s.create_fun(5);
    int c = s.get_c();
    EXPECT_EQ(c, 4);
    EXPECT_EQ(ans1, 5);
    EXPECT_EQ(ans2, 20);
    EXPECT_EQ(ans3, 29);
}

TEST(FunctionTests, Sqrc_CreateValueSetShift2) {
    Function s(Type::sqrc, -1);
    s.set_c(0);

    int ans1 = s.create_fun(2);
    int ans2 = s.create_fun(3);
    int ans3 = s.create_fun(6);
    int c = s.get_c();
    EXPECT_EQ(c, 0);
    EXPECT_EQ(ans1, 4);
    EXPECT_EQ(ans2, 9);
    EXPECT_EQ(ans3, 36);
}