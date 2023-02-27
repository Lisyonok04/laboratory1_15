#include <gtest/gtest.h>

#include <function/function.h>

using namespace function;



TEST(FunctionListTests, CapacityCheck) {
    Function_List functions;
    const auto f = Function::create_sqrc(3);
    for (int i = 0; i < Function_List::CAPACITY; ++i) {
        functions.add(f);
    }

    ASSERT_ANY_THROW(functions.add(f));

}



TEST(IndexOfFunctionWithMinValue, NoResult) {
    Function_List functions;

    const auto index = index_of_min_value(functions, 0);

    ASSERT_EQ(index, -1);
}

TEST(IndexOfFunctionWithMinValue, ArgZero) {
    Function_List functions;
    functions.add(Function::create_sqrc(1));
    functions.add(Function::create_sqrc(2));
    functions.add(Function::create_sqrc(2));
    functions.add(Function::create_sqrc(1));

    const auto index = index_of_min_value(functions, 4);

    ASSERT_EQ(index, 0);
}

TEST(IndexOfFunctionWithMinValue, Arg12) {
    Function_List functions;
    functions.add(Function::create_sqrc(2));
    functions.add(Function::create_sqrc(1));
    functions.add(Function::create_sqrc(1));
    functions.add(Function::create_sqrc(2));

    const auto index = index_of_min_value(functions, 12);

    ASSERT_EQ(index, 1);
}
