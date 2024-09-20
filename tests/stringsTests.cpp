
#include <gtest/gtest.h>
#include <strings.hpp>
#include <console.hpp>

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

TEST(stringsTest, EqIgnoreCaseTrue)
{
    string a = "pizza";
    string b = "PIZZA";
    EXPECT_TRUE(equalsIgnoreCase(a, b));
}

TEST(stringsTest, EqIgnoreCaseFalse)
{
    string a = "pizza";
    string b = "PIXZA";
    EXPECT_FALSE(equalsIgnoreCase(a, b));
}

TEST(stringsTest, MatchIgnoreCase)
{
    string s = "CHESS";
    string pattern ="poker|chess";
    EXPECT_TRUE(matchIgnoreCase(s, pattern));
}

TEST(stringsTest, ToUpper)
{
    string s = "Chess";
    EXPECT_EQ("CHESS", toUppercase(s));
}

TEST(stringsTest, ToLower)
{
    string s = "Chess";
    EXPECT_EQ("chess", toLowercase(s));
}