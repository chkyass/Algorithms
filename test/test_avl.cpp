#include <include/catch.hh>
#include <src/avl.hpp>
#include <random>

TEST_CASE("single node avl", "[avl]")
{
  avl<int> a(0);
  REQUIRE(a.size()==1);
  REQUIRE(a.height()==0);
}


TEST_CASE("test contain one node", "[avl]")
{
  avl<int> a(0);
  REQUIRE(a.contain(0));
}

TEST_CASE("test contain multiple nodes", "[avl]")
{
  avl<int> a(0);
  a.insert(1);
  a.insert(-1);
  REQUIRE(a.size() == 3);
  REQUIRE(a.height() == 1);
  REQUIRE(a.contain(0));
  REQUIRE(a.contain(1));
  REQUIRE(a.contain(-1));
}


TEST_CASE("test insert one node", "[avl]")
{
  avl<int> a(0);
  a.insert(1);
  REQUIRE(a.size()==2);
  REQUIRE(a.height()==1);
}

TEST_CASE("right right case", "[avl]")
{
  avl<int> a(0);
  a.insert(1);
  a.insert(2);
  REQUIRE(a.size() == 3);
  REQUIRE(a.height() == 1);
  REQUIRE(a.contain(0));
  REQUIRE(a.contain(1));
  REQUIRE(a.contain(2));
}

TEST_CASE("left left case", "[avl]")
{
  avl<int> a(0);
  a.insert(-1);
  a.insert(-2);
  REQUIRE(a.size() == 3);
  REQUIRE(a.height() == 1);
  REQUIRE(a.contain(0));
  REQUIRE(a.contain(-1));
  REQUIRE(a.contain(-2));
}

TEST_CASE("right left case", "[avl]")
{
  avl<int> a(0);
  a.insert(2);
  a.insert(1);
  REQUIRE(a.size() == 3);
  REQUIRE(a.height() == 1);
  REQUIRE(a.contain(0));
  REQUIRE(a.contain(2));
  REQUIRE(a.contain(1));
}

TEST_CASE("left right case", "[avl]")
{
  avl<int> a(0);
  a.insert(-2);
  a.insert(-1);
  REQUIRE(a.size() == 3);
  REQUIRE(a.height() == 1);
  REQUIRE(a.contain(0));
  REQUIRE(a.contain(-2));
  REQUIRE(a.contain(-1));
}

TEST_CASE("random insert and height stability", "[avl]")
{
  avl<int> a(0);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dis(-1000000000, 1000000000);

  std::stack<int> generated;

  for(int i = 0; i<1000000; i++)
  {
    generated.push(dis(gen));
    a.insert(generated.top());
    REQUIRE(a.height() < 1.44*log2(a.size()));
  }
  
  for(int i = 0; i<10000000; i++)
  {
    REQUIRE(a.contain(generated.top()) == true);
    generated.pop();
  }
}