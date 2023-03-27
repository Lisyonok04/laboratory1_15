#include <gtest/gtest.h>

#include <function/function.h>

using namespace function;

TEST(FunctionListTests, CapacityCheck) {
    Function_List sequence;

    const auto s = Function::Function(Type::sqrc, 0);
    for (int i = 0; i < Function_List::capacity; ++i) {
        sequence.insert(i, s);

    }
    ASSERT_ANY_THROW(sequence.insert(10, s));

}

TEST(IndexOfSequenceWithMinValue, NoResult) {
    Function_List sequence;

    auto index = index_of_min_value(sequence, 2);

    ASSERT_EQ(index, -1);
}

TEST(IndexOfSequenceWithMinValue, ForSquares1) {
    Function_List sequence;

    sequence.insert(0, Function::Function(Type::sqrc, 0));
    sequence.insert(1, Function::Function(Type::sqrc, 1));
    sequence.insert(2, Function::Function(Type::sqrc, 1));
    sequence.insert(3, Function::Function(Type::sqrc, 0));

    auto index = index_of_min_value(sequence, 0);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, ForSquares2) {
    Function_List sequence;

    sequence.insert(0, Function::Function(Type::sqrc, 1));
    sequence.insert(1, Function::Function(Type::sqrc, 2));
    sequence.insert(2, Function::Function(Type::sqrc, 3));
    sequence.insert(3, Function::Function(Type::sqrc, 4));

    auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 0);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials1) {
    Function_List sequence;

    sequence.insert(0, Function::Function(Type::fack));
    sequence.insert(1, Function::Function(Type::fack));
    sequence.insert(2, Function::Function(Type::fack));
    sequence.insert(3, Function::Function(Type::fack));

    auto index = index_of_min_value(sequence, 0);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials2) {
    Function_List sequence;

    sequence.insert(0, Function::Function(Type::fack));
    sequence.insert(1, Function::Function(Type::fack));
    sequence.insert(2, Function::Function(Type::fack));
    sequence.insert(3, Function::Function(Type::fack));

    auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, Mix1) {
    Function_List sequence;

    sequence.insert(0, Function::Function(Type::fack));
    sequence.insert(1, Function::Function(Type::sqrc, 3));
    sequence.insert(2, Function::Function(Type::fack));
    sequence.insert(3, Function::Function(Type::sqrc, 0));

    auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, Mix2) {
    Function_List sequence;

    sequence.insert(0, Function::Function(Type::sqrc, 0));
    sequence.insert(1, Function::Function(Type::fack));
    sequence.insert(2, Function::Function(Type::sqrc, 3));
    sequence.insert(3, Function::Function(Type::sqrc, 4));

    auto index = index_of_min_value(sequence, 1);

    ASSERT_EQ(index, 1);
}

TEST(IndexOfSequenceWithMinValue, Mix3) {
    Function_List sequence;

    sequence.insert(0, Function::Function(Type::fack));
    sequence.insert(1, Function::Function(Type::sqrc, 2));
    sequence.insert(2, Function::Function(Type::sqrc, 1));
    sequence.insert(3, Function::Function(Type::sqrc, 3));

    auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 2);
}

TEST(IndexOfSequenceWithMinValue, Mix4) {
    Function_List sequence;

    sequence.insert(0, Function::Function(Type::fack));
    sequence.insert(1, Function::Function(Type::fack));
    sequence.insert(2, Function::Function(Type::sqrc, 1));
    sequence.insert(3, Function::Function(Type::fack));
    sequence.insert(4, Function::Function(Type::sqrc, 3));
    sequence.insert(5, Function::Function(Type::sqrc, 5));
    sequence.insert(6, Function::Function(Type::fack));
    sequence.insert(7, Function::Function(Type::sqrc, 1));
    sequence.insert(8, Function::Function(Type::sqrc, 7));
    sequence.insert(9, Function::Function(Type::fack));

    auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 7);
}

TEST(IndexOfSequenceWithMinValue, Mix5) {
    Function_List sequence;

    sequence.insert(0, Function::Function(Type::fack));
    sequence.insert(1, Function::Function(Type::fack));
    sequence.insert(2, Function::Function(Type::sqrc, 4));
    sequence.insert(3, Function::Function(Type::fack));
    sequence.insert(4, Function::Function(Type::sqrc, 3));
    sequence.insert(5, Function::Function(Type::sqrc, 5));
    sequence.insert(6, Function::Function(Type::fack));
    sequence.insert(7, Function::Function(Type::sqrc, 8));
    sequence.insert(8, Function::Function(Type::sqrc, 7));
    sequence.insert(9, Function::Function(Type::fack));

    auto index = index_of_min_value(sequence, 1);

    ASSERT_EQ(index, 9);
}