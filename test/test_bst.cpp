#define CATCH_CONFIG_MAIN 
#include "include/catch.hh"
#include "src/bst.hpp"

TEST_CASE("Test contain singleton", "[bst]")
{
  bst<int> tree(0);
  REQUIRE(tree.contain(0) == true);
  REQUIRE(tree.size() == 1);
}

TEST_CASE("Test not contain songleton", "[bst]")
{
  bst<int> tree(0);
  REQUIRE(tree.contain(1) == false);
  REQUIRE(tree.size() == 1);
}

TEST_CASE("Test insert", "[bst]")
{
  bst<int> tree(0);
  REQUIRE(tree.contain(1) == false);
  REQUIRE(tree.size() == 1);

  tree.insert(1);
  REQUIRE(tree.contain(1) == true);
  REQUIRE(tree.contain(0) == true);
  REQUIRE(tree.size() == 2);

  tree.insert(2);
  REQUIRE(tree.contain(2) == true);
  REQUIRE(tree.contain(3) == true);
  REQUIRE(tree.size() == 3);
}

TEST_CASE("Test insert existing element", "[bst]")
{
  bst<int> tree(0);
  tree.insert(0);
  REQUIRE(tree.contain(0) == true);
  REQUIRE(tree.size() == 1);

  tree.insert(0);
  REQUIRE(tree.contain(2) == true);
  REQUIRE(tree.contain(3) == true);
  REQUIRE(tree.size() == 1);
}

