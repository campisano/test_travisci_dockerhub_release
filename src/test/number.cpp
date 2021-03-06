#include "testutils.hpp"
#include "../2048/domain/number.hpp"

namespace
{
const Number::Value ARBITRARY_VALUE = 8;
}

TEST_GROUP(NumberTest) {};

TEST(NumberTest, Creation)
{
    Number number(ARBITRARY_VALUE);
    CHECK_EQUAL(ARBITRARY_VALUE, number.value());
}

TEST(NumberTest, CreationByMake)
{
    auto number = Number::make(ARBITRARY_VALUE);
    CHECK_TRUE(number);
    CHECK_EQUAL(ARBITRARY_VALUE, number->value());
}

TEST(NumberTest, ThrowsOnCreationWithValueLessThanTwo)
{
    CHECK_THROWS_STDEXCEPT(
        std::runtime_error, "value cannot be less than 2", Number(1));
}

TEST(NumberTest, ThrowsOnCreationWithValue3NotPowerOf2)
{
    CHECK_THROWS_STDEXCEPT(
        std::runtime_error, "value must be power of 2", Number(3));
}

TEST(NumberTest, ThrowsOnCreationWithValue6NotPowerOf2)
{
    CHECK_THROWS_STDEXCEPT(
        std::runtime_error, "value must be power of 2", Number(6));
}
