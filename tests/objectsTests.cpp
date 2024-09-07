
#include <gtest/gtest.h>
#include <objects.hpp>
using namespace objects;

TEST(objectsTest, ConstructNewDelete)
{
    auto s = construct<string>("my string");
    EXPECT_EQ(*s, "my string");
    destroy(s);
}

TEST(objectsTest, ConstructAllocator)
{
    allocator<string> a;
    auto s = construct<string>(a, "my string");
    EXPECT_EQ(*s, "my string");
    destroy(a, s);
}

TEST(objectsTest, SmartPtr)
{
    SmartPtr<string> s("my string");
    EXPECT_EQ(*s, "my string");
}
