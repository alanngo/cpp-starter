
#include <gtest/gtest.h>
#include <strings.hpp>

using namespace strings;

TEST(stringsTest, Split)
{
    string s = "king<>queen<>rook<>bishop<>knight<>pawn";
    vector<string> expected = {"king", "queen", "rook", "bishop", "knight", "pawn"};
    auto actual = split(s, "<>");

    for (size_t i = 0; i < expected.size(); i++)
        EXPECT_EQ(actual[i], expected[i]);

    EXPECT_EQ(expected.size(), actual.size());
}

TEST(stringsTest, Join)
{
    string chess = join({"king", "queen", "rook", "bishop", "knight", "pawn"}, "<>");
    EXPECT_EQ(chess, "king<>queen<>rook<>bishop<>knight<>pawn");
}
