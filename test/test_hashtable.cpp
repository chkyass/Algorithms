#include "include/catch.hh"
#include "src/hashtable.hpp"
#include <array>

std::array<size_t, 100> primes = {{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                              47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
                              107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
                              167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227,
                              229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281,
                              283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353,
                              359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421,
                              431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487,
                              491, 499, 503, 509, 521, 523, 541 }};

TEST_CASE("isPrime", "[hashtable]")
{
  hashtable<int,int> h;
  for (auto& e : primes)
    REQUIRE(h.isPrime(e) == true);
}

TEST_CASE("nextPrime", "[hastable]")
{
  hashtable<int,int> h;
  for(size_t i = 1; i < primes.size()-1; i++)
    REQUIRE(h.nextPrime(primes[i]) == primes[i+1]);
}

TEST_CASE("insert new val", "[hashtable]")
{
  hashtable<int, int> h;
  h.insert(1,2);
  h.insert(1,2);
  h.insert(2,4);
  REQUIRE(*(h.get(1)) == 2);
}

TEST_CASE("insert with reash", "[hashtable]")
{
  hashtable<int, int> h;
  h.insert(1,2);
  h.insert(2,2);
  h.insert(3,4);
  REQUIRE(*(h.get(1)) == 2);
  REQUIRE(*(h.get(2)) == 2);
  REQUIRE(*(h.get(3)) == 4);
}

TEST_CASE("remove", "[hashtable]")
{
  hashtable<int, int> h;
  h.insert(1,2);
  h.insert(2,2);
  h.insert(3,4);
  h.insert(4,2);
  h.insert(5,3);
  h.insert(6,1);
  REQUIRE(*(h.get(1)) == 2);
  REQUIRE(*(h.get(2)) == 2);
  REQUIRE(*(h.get(3)) == 4);
  h.remove(1);
  REQUIRE(h.get(1) == nullptr);
  h.remove(2);
  REQUIRE(h.get(2) == nullptr);
  h.remove(3);
  REQUIRE(h.get(3) == nullptr);
}

TEST_CASE("remove with reash", "[hashtable]")
{
  hashtable<int, int> h;
  h.insert(1,2);
  h.insert(2,2);
  h.insert(3,4);
  h.insert(4,2);

  h.remove(1);
  REQUIRE(*(h.get(2)) == 2);
  REQUIRE(*(h.get(3)) == 4);
  REQUIRE(*(h.get(4)) == 2);
}

TEST_CASE("make empty", "[hashtable]")
{
  hashtable<int, int> h;
  h.insert(1,2);
  h.insert(2,2);
  h.remove(1);
}

TEST_CASE("multiple extend and shrink", "[hashtable]")
{
  hashtable<int, int> h;
  for(size_t i = 0; i < 100; i ++)
    h.insert(i,i);
  for(size_t i = 0; i < 100; i ++)
    REQUIRE(*h.get(i) == i);
  for(size_t i = 0; i < 100; i ++)
    h.remove(i);
}


