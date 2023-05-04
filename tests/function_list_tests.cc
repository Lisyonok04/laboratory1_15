#include <gtest/gtest.h>

#include <function/function.h>

using namespace function;

TEST(FunctionListTests, CapacityCheck) {
    Function_List sequence(3);
    sequence[0] = Function(Type::sqrc, 3);
    sequence[1] = Function(Type::sqrc, 2);
    sequence[2] = Function(Type::sqrc, 5);
    Function s = Function(Type::sqrc, 4);
    ASSERT_ANY_THROW(sequence.insert(4, s););
}

TEST(IndexOfSequenceWithMinValue, NoResult) {
    Function_List sequence;

    const auto index = index_of_min_value(sequence, 2);

    ASSERT_EQ(index, -1);
}

TEST(IndexOfSequenceWithMinValue, ForSquares1) {
    Function_List sequence;
    Function s = Function(Type::sqrc, 0);
    Function s1 = Function(Type::sqrc, 1);
    sequence.insert(0, s);
    sequence.insert(1, s1);
    sequence.insert(2, s1);
    sequence.insert(3, s);

    const auto index = index_of_min_value(sequence, 0);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, ForSquares2) {
    Function_List sequence;
    Function s = Function(Type::sqrc, 1);
    Function s1 = Function(Type::sqrc, 2);
    Function s2 = Function(Type::sqrc, 3);
    Function s3 = Function(Type::sqrc, 4);
    sequence.insert(0, s);
    sequence.insert(1, s1);
    sequence.insert(2, s2);
    sequence.insert(3, s3);

    const auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 0);
}

TEST(IndexOfSequenceWithMinValue, ForSquares3) {
    Function_List sequence;
    Function s = Function(Type::sqrc, 1);
    Function s1 = Function(Type::sqrc, 2);
    Function s2 = Function(Type::sqrc, 3);
    Function s3 = Function(Type::sqrc, 4);
    sequence.insert(0, s);
    sequence.insert(1, s1);
    sequence.insert(2, s2);
    sequence.insert(3, s3);

    const auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 0);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials1) {
    Function_List sequence;
    Function s = Function(Type::fack);
    Function s1 = Function(Type::fack);
    Function s2 = Function(Type::fack);
    Function s3 = Function(Type::fack);
    sequence.insert(0, s);
    sequence.insert(1, s1);
    sequence.insert(2, s2);
    sequence.insert(3, s3);

    const auto index = index_of_min_value(sequence, 0);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, ForFactorials2) {
    Function_List sequence;
    Function s = Function(Type::fack);
    Function s1 = Function(Type::fack);
    Function s2 = Function(Type::fack);
    Function s3 = Function(Type::fack);
    sequence.insert(0, s);
    sequence.insert(1, s1);
    sequence.insert(2, s2);
    sequence.insert(3, s3);

    const auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 3);
}

TEST(IndexOfSequenceWithMinValue, Mix1) {
    Function_List sequence;
    Function s = Function(Type::fack);
    Function s1 = Function(Type::fack);
    Function s2 = Function(Type::sqrc, 3);
    Function s3 = Function(Type::fack);
    Function s4 = Function(Type::fack);
    sequence.insert(0, s);
    sequence.insert(1, s1);
    sequence.insert(2, s2);
    sequence.insert(3, s3);
    sequence.insert(4, s4);

    const auto index = index_of_min_value(sequence, 0);

    ASSERT_EQ(index, 4);
}

TEST(IndexOfSequenceWithMinValue, Mix2) {
    Function_List sequence;
    Function s = Function(Type::sqrc, 0);
    Function s1 = Function(Type::fack);
    Function s2 = Function(Type::sqrc, 3);
    Function s3 = Function(Type::sqrc, 4);
    sequence.insert(0, s);
    sequence.insert(1, s1);
    sequence.insert(2, s2);
    sequence.insert(3, s3);

    const auto index = index_of_min_value(sequence, 1);

    ASSERT_EQ(index, 1);
}

TEST(IndexOfSequenceWithMinValue, Mix3) {
    Function_List sequence;
    Function s = Function(Type::fack);
    Function s1 = Function(Type::fack);
    Function s2 = Function(Type::sqrc, 1);
    Function s3 = Function(Type::fack);
    Function s4 = Function(Type::sqrc, 3);
    Function s5 = Function(Type::sqrc, 5);
    Function s6 = Function(Type::fack);
    Function s7 = Function(Type::sqrc, 1);
    Function s8 = Function(Type::sqrc, 7);
    Function s9 = Function(Type::fack);
    sequence.insert(0, s);
    sequence.insert(1, s1);
    sequence.insert(2, s2);
    sequence.insert(3, s3);
    sequence.insert(4, s4);
    sequence.insert(5, s5);
    sequence.insert(6, s6);
    sequence.insert(7, s7);
    sequence.insert(8, s8);
    sequence.insert(9, s9);


    const auto index = index_of_min_value(sequence, 5);

    ASSERT_EQ(index, 7);
}

TEST(IndexOfSequenceWithMinValue, Mix4) {
    Function_List sequence;
    Function s = Function(Type::fack);
    Function s1 = Function(Type::fack);
    Function s2 = Function(Type::sqrc, 4);
    Function s3 = Function(Type::fack);
    Function s4 = Function(Type::sqrc, 3);
    Function s5 = Function(Type::sqrc, 5);
    Function s6 = Function(Type::fack);
    Function s7 = Function(Type::sqrc, 8);
    Function s8 = Function(Type::sqrc, 7);
    Function s9 = Function(Type::fack);
    sequence.insert(0, s);
    sequence.insert(1, s1);
    sequence.insert(2, s2);
    sequence.insert(3, s3);
    sequence.insert(4, s4);
    sequence.insert(5, s5);
    sequence.insert(6, s6);
    sequence.insert(7, s7);
    sequence.insert(8, s8);
    sequence.insert(9, s9);

    auto index = index_of_min_value(sequence, 1);

    ASSERT_EQ(index, 9);
}