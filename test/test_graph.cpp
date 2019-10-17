#include "include/catch.hh"
#include "src/graph.hpp"
#include <iostream>
#include <unordered_set>

TEST_CASE("add element to graph", "[graph]")
{
  graph<int> g;
  g.add(6, {2, 3, 4});
  REQUIRE(g.getVertices().size() == 4);
}

TEST_CASE("bfs direceted acyclique", "[graph]")
{
  graph<int> g;
  g.add(6, {2, 3, 4});
  g.add(2, {5});
  g.add(3, {7, 8});
  g.add(4, {9, 10});

  std::vector<int> ret;
  g.bfs(6, [&ret](int v) { 
    ret.push_back(v);
    });
  REQUIRE(ret == std::vector<int> {6, 2, 3, 4, 5, 7, 8, 9, 10});

}

TEST_CASE("bfs cycle", "[graph]")
{
  graph<int> g;
  g.add(1, {2});
  g.add(2, {3});
  g.add(3, {1});

  std::vector<int> ret;
  g.bfs(2, [&ret](int v) { 
    ret.push_back(v);
    });
  REQUIRE(ret == std::vector<int> {2, 3, 1});
}


TEST_CASE("bfs complete graph", "[graph]")
{
  graph<int> g;
  g.add(1, {2});
  g.add(2, {1});
  g.add(2, {3});
  g.add(3, {2});
  g.add(3, {1});
  g.add(1, {3});

  std::vector<int> ret;
  g.bfs(2, [&ret](int v) { 
    ret.push_back(v);
    });
  REQUIRE(ret == std::vector<int> {2, 3, 1});
}

TEST_CASE("dfs direceted acyclique", "[graph]")
{
  graph<int> g;
  g.add(6, {2, 3, 4});
  g.add(2, {5});
  g.add(3, {7, 8});
  g.add(4, {9, 10});

  std::vector<int> ret;
  g.dfs(6, [&ret](int v) { 
    ret.push_back(v);
    });
  REQUIRE(ret == std::vector<int> {6, 2, 5, 3, 7, 8, 4, 9, 10});
}

TEST_CASE("dfs cycle", "[graph]")
{
  graph<int> g;
  g.add(1, {2});
  g.add(2, {3});
  g.add(3, {1});

  std::vector<int> ret;
  g.dfs(2, [&ret](int v) { 
    ret.push_back(v);
    });
  REQUIRE(ret == std::vector<int> {2, 3, 1});
}

TEST_CASE("dfs complete graph", "[graph]")
{
  graph<int> g;
  g.add(1, {2});
  g.add(2, {1});
  g.add(2, {3});
  g.add(3, {2});
  g.add(3, {1});
  g.add(1, {3});

  std::vector<int> ret;
  g.dfs(2, [&ret](int v) { 
    ret.push_back(v);
    });
  REQUIRE(ret == std::vector<int> {2, 3, 1});
}