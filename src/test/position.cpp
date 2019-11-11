#include "testutils.hpp"
#include "../2048/domain/position.hpp"

namespace
{
const Value ARBITRARY_VALUE = 8;
}

TEST_GROUP(PositionTest) {};

TEST(PositionTest, Creation)
{
    Position position;
    CHECK_FALSE(position.number());
}

TEST(PositionTest, PlacingNumber)
{
    auto number = Number::create(ARBITRARY_VALUE);
    Number * num_ptr = number.get();
    Position position;
    position.place(number);
    CHECK_FALSE(number);
    CHECK_TRUE(position.number());
    CHECK_EQUAL(num_ptr, position.number().get());
}

TEST(PositionTest, PlacingNumberTwiceThrowsException)
{
    auto n1 = Number::create(ARBITRARY_VALUE);
    auto n2 = Number::create(ARBITRARY_VALUE);
    Position pos;
    pos.place(n1);
    CHECK_THROWS_STDEXCEPT(
        std::runtime_error, "position already contain a number", pos.place(n2));
}
