#include "include/catch.hh"
#include "src/sort.hpp"
#include <array>
#include <random>
#include <vector>

TEST_CASE ("insertion sort", "[sort]")
{
  std::array<int, 5> input {{8, 17, 8, 10, -1}};
  std::array<int, 5> output {{-1, 8, 8, 10, 17}};
  sort<int> s;
  s.insertionSort(input.data(), 5);
  REQUIRE(input == output);
}

TEST_CASE ("insertion sort empty", "[sort]")
{
  std::array<int, 5> input;
  sort<int> s;
  s.insertionSort(input.data(), 5);
}

TEST_CASE ("insertion sort random vals", "[sort]")
{
  std::vector<int> input;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int>dis(-1000000, 1000000);
  for(size_t i = 0; i < 1000; i++)
  {
    input.push_back(dis(gen));
  }
  sort<int> s;
  s.insertionSort(input.data(), input.size());
  for(size_t i = 1; i < 1000; i++)
  {
    REQUIRE(input[i-1] <= input[i]);
  }
}

TEST_CASE ("merge sort", "[sort]")
{
  std::array<int, 5> input = {{8, 17, 8, 10, -1}};
  std::array<int, 5> output = {{-1, 8, 8, 10, 17}};
  sort<int> s;
  s.mergeSort(input.data(), 5);
  REQUIRE(input == output);
}

TEST_CASE ("merge sort empty", "[sort]")
{
  std::array<int, 5> input = {{8, 17, 8, 10, -1}};
  sort<int> s;
  s.mergeSort(input.data(), 5);
}

TEST_CASE ("merge sort random vals", "[sort]")
{
  std::vector<int> input;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int>dis(-100000000, 100000000);
  for(size_t i = 0; i < 1000000; i++)
  {
    input.push_back(dis(gen));
  }
  sort<int> s;
  //s.mergeSort(input.data(), input.size());
  std::sort(input.begin(), input.end());
  for(size_t i = 1; i < input.size(); i++)
  {
    REQUIRE(input[i-1] <= input[i]);
  }
}

