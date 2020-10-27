#include "class1.h"
#include <gtest/gtest.h>

TEST(FooTest, EqualToZero) {
    ASSERT_EQ(0, Foo(1337));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
    
