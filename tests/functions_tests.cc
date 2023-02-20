#include <gtest/gtest.h>

#include <functions/functions.h>

TEST(FunctionsTests, SumStubTest1) {
    // Arrange
    int lhs = 2;
    int rhs = 3;
    
    // Act
    int r = sum_stub(lhs, rhs);
    
    // Assert
    EXPECT_EQ(r, 0);
}

TEST(FunctionsTests, SumStubTest2) {
    // Arrange
    int lhs = -1;
    int rhs = 3;
    
    // Act
    int r = sum_stub(lhs, rhs);
    
    // Assert
    EXPECT_EQ(r, 36);
}
TEST(FunctionsTests, SumStubTest3) {
    // Arrange
    int lhs = 7;
    int rhs = 3;
    
    // Act
    int r = sum_stub(lhs, rhs);
    
    // Assert
    EXPECT_EQ(r, 60);
}
