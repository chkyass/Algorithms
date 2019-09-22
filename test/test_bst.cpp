#include "include/catch.hh"
#include "src/bst.hpp"

TEST_CASE("Test contain", "[bst]")
{
  bst<int> tree(0);
  REQUIRE(tree.contain(0) == true);
  REQUIRE(tree.size() == 1);
}

TEST_CASE("Test doesn't contain", "[bst]")
{
  bst<int> tree(0);
  REQUIRE(tree.contain(1) == false);
  REQUIRE(tree.size() == 1);
}

TEST_CASE("Test insert", "[bst]")
{
  bst<int> tree(0);
  tree.insert(1);
  tree.insert(3);
  tree.insert(5);
  tree.insert(7);
  tree.insert(4);
  tree.insert(6);
  tree.insert(2);


  REQUIRE(tree.contain(0) == true);
  REQUIRE(tree.contain(1) == true);
  REQUIRE(tree.contain(2) == true);
  REQUIRE(tree.contain(3) == true);
  REQUIRE(tree.contain(4) == true);
  REQUIRE(tree.contain(5) == true);
  REQUIRE(tree.contain(6) == true);
  REQUIRE(tree.contain(7) == true);
  REQUIRE(tree.size() == 8);
}

TEST_CASE("Test insert existing element", "[bst]")
{
  bst<int> tree(0);
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  tree.insert(4);
  tree.insert(5);
  tree.insert(6);
  tree.insert(7);
  // first left
  tree.insert(1);
  // first right
  tree.insert(2);
  // somwhere in the tree
  tree.insert(4);
  REQUIRE(tree.size() == 8);
}
