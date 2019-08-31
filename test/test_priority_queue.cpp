#define CATCH_CONFIG_MAIN 
#include "include/catch.hh"
#include "src/priority_queue.hpp"
#include <string>
#include <iostream>

TEST_CASE( "Empty queue", "[priority queue]" ) 
{
    std::vector<int> a;
    priority_queue<int> p(a);
    REQUIRE(p.isEmpty() == true);
}

TEST_CASE( "Singleton", "[priority queue]" )
{
    std::vector<int> a{1};
    priority_queue<int> p(a);
    REQUIRE(p.isEmpty() == false);
}

TEST_CASE( "Test pop", "[priority queue]")
{
  std::vector<int> a{1,3,6,2};
  priority_queue<int> p(a);
  REQUIRE(p.pop() == 6);
  REQUIRE(p.pop() == 3);
}

TEST_CASE( "Test add", "[priority queue]")
{
  std::vector<int> a{1};
  priority_queue<int> p(a);
  p.add(2);
  p.add(3);
  REQUIRE(p.top() == 3);
}

TEST_CASE( "Test top", "[priority queue]")
{
  std::vector<int> a{1,3,6,2};
  priority_queue<int> p(a);
  p.add(2);
  p.add(6);
  REQUIRE(p.top() == 6);
  REQUIRE(p.top() == 6);

}

TEST_CASE( "Test min heap top and pop", "[priority queue]")
{
  std::vector<int> a{1,3,6,2,-10};
  priority_queue<int> p(a, -1);
  p.add(2);
  p.add(6);
  REQUIRE(p.pop() == -10);
  REQUIRE(p.top() == 1);

}

TEST_CASE("TEST replace element", "[priority queue]")
{
  std::vector<int>a{1,2,3};
  priority_queue<int> p(a);
  REQUIRE(p.top() == 3);
  p.replace(3, 0);
  REQUIRE(p.top() == 2);
  p.replace(1, -1);
  REQUIRE(p.top() == 2);
  p.replace(2, 10);
  REQUIRE(p.pop() == 10);
}

TEST_CASE( "Test min heap add", "[priority queue]")
{
  std::vector<int> a{1};
  priority_queue<int> p(a, -1);
  p.add(2);
  p.add(3);
  REQUIRE(p.top() == 1);
}
