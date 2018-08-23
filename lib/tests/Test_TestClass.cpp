#include <gtest/gtest.h>

#include <Library.h>

TEST(Library_TestClass, DefaultCountValue) {
    TestClass sut;
    EXPECT_EQ(sut.GetCount(), 0);
}

TEST(Library_TestClass, Increment) {
    TestClass sut;
    sut.Increment();
    EXPECT_EQ(sut.GetCount(), 1);
}

