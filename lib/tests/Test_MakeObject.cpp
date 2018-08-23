#include <gtest/gtest.h>

#include <Library.h>

TEST(Library_TestClass, DefaultCountValue) {
    TestClass sut = MakeObject();

    #ifdef _WIN32
        EXPECT_EQ(sut.GetCount(), 666);
    #endif

    #ifdef linux
        EXPECT_EQ(sut.GetCount(), 42);
    #endif
}

