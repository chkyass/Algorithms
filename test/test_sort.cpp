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
  std::uniform_int_distribution<unsigned int>dis1(0, 100000);

  for(size_t i = 0; i < dis1(gen); i++)
  {
    input.push_back(dis(gen));
  }
  sort<int> s;
  s.mergeSort(input.data(), input.size());
  for(size_t i = 1; i < input.size(); i++)
  {
    REQUIRE(input[i-1] <= input[i]);
  }
}

TEST_CASE ("test quicksort sort", "[sort]")
{
  std::array<int, 5> input = {{8, 17, 8, 10, -1}};
  std::array<int, 5> output = {{-1, 8, 8, 10, 17}};
  sort<int> s;
  s.quickSort(input.data(), 5);
  REQUIRE(input == output);
}

TEST_CASE ("quicksort sort random vals", "[sort]")
{
  std::vector<int> input;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int>dis(-100000000, 100000000);
  std::uniform_int_distribution<unsigned int>dis1(1000, 100000);

  for(size_t i = 0; i < dis1(gen); i++)
  {
    input.push_back(dis(gen));
  }
  sort<int> s;
  s.quickSort(input.data(), input.size());
  for(size_t i = 1; i < input.size(); i++)
  {
    REQUIRE(input[i-1] <= input[i]);
  }
}

TEST_CASE("countSort8 simple case", "[sort]")
{
  std::array<int, 6> input {{ 0, 2, 1, 10, 255, 33 }};
  std::array<int, 6> output {{0, 1, 2, 10, 33, 255}};
  
  sort<int> s;
  s.countSort8(input.data(), input.size(), 0);
  REQUIRE(output == input);
}

TEST_CASE("radixSort simple case", "[sort]")
{
  std::array<int, 6> input {{ 0, 2, 1, 10, 255, 33 }};
  std::array<int, 6> output {{ 0, 1, 2, 10, 33, 255 }};
  
  sort<int> s;
  s.radixSort(input.data(), input.size());
  REQUIRE(output == input);
}

TEST_CASE ("radixsort random vals", "[sort]")
{
  std::vector<int> input;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int>dis(0, 1000000);
  std::uniform_int_distribution<unsigned int>dis1(1000, 100000);

  for(size_t i = 0; i < 10; i++)
  {
    input.push_back(dis(gen));
  }
  sort<int> s;
  s.radixSort(input.data(), input.size());
  for(size_t i = 1; i < input.size(); i++)
  {
    REQUIRE(input[i-1] <= input[i]);
  }
}

