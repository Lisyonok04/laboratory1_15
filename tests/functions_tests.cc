#include <gtest/gtest.h>

#include <function/function.h>

using namespace function;

TEST(FunctionTests, Fack_CreateValue) {
    auto fack1 = Function::create_fack();
    EXPECT_EQ(fack1.create_fun(3), 6);
    auto fack2 = Function::create_fack();
    EXPECT_EQ(fack2.create_fun(7), 5040);
    auto fack3 = Function::create_fack();
    EXPECT_EQ(fack3.create_fun(5), 120);
    auto fack4 = Function::create_fack();
    EXPECT_EQ(fack4.create_fun(0), 1);
}


TEST(FunctionTests, Sqrc_CreateValue) {
    auto sqrc1 = Function::create_sqrc(1);
    EXPECT_EQ(sqrc1.create_fun(3), 10);
    auto sqrc2 = Function::create_sqrc(2);
    EXPECT_EQ(sqrc2.create_fun(4), 18);
    auto sqrc3 = Function::create_sqrc(0);
    EXPECT_EQ(sqrc3.create_fun(5), 25);
    auto sqrc4 = Function::create_sqrc(3);
    EXPECT_EQ(sqrc4.create_fun(0),3);
    auto sqrc5 = Function::create_sqrc(-3);
    EXPECT_EQ(sqrc5.create_fun(5), 22);
    auto sqrc6 = Function::create_sqrc(4);
    EXPECT_EQ(sqrc6.create_fun(-2), 8);
}
