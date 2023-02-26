#include <gtest/gtest.h>

#include <function/function.h>

using namespace function;

TEST(FunctionTests, Fack_CreateValue) {
    auto fack1 = Function::create_fack();
    EXPECT_EQ(fack1.create_fun(5), 120);
    EXPECT_EQ(fack1.create_fun(2), 2);
    EXPECT_EQ(fack1.create_fun(1), 1);
    EXPECT_EQ(fack1.create_fun(0), 1);

}


TEST(FunctionTests, Sqrc_CreateValue) {
    auto sqrc1 = Function::create_sqrc(1);
    auto sqrc2 = Function::create_sqrc(3);

    EXPECT_EQ(sqrc1.create_fun(0), 1);
    EXPECT_EQ(sqrc1.create_fun(2), 5);
    EXPECT_EQ(sqrc1.create_fun(-3), 10);
    EXPECT_EQ(sqrc1.create_fun(1), 2);

    EXPECT_EQ(sqrc2.create_fun(0), 3);
    EXPECT_EQ(sqrc2.create_fun(2), 7);
    EXPECT_EQ(sqrc2.create_fun(-3), 12);
    EXPECT_EQ(sqrc2.create_fun(1), 4);
}
