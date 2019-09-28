#include <benchmark/benchmark.h>
#include "../src/sort.hpp"
#include <random>
#include <array>
#include <algorithm>
#include <boost/sort/spreadsort/spreadsort.hpp>
#include <boost/sort/sort.hpp>


#define SIZE 10000000
#define TYPE int
static std::array<TYPE, SIZE> input;


static int getRandomNumber()
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<int>dis(-100000000, 100000000);
  return dis(gen);
}

static void BM_mergesort(benchmark::State& state) {
  sort<int> s;

  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    s.mergeSort(input.data(), state.range(0));
  }
}

static void BM_radixsort(benchmark::State& state) {
  sort<int> s;

  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    s.radixSort(input.data(), state.range(0));
  }
}

static void BM_quicksort(benchmark::State& state) {
  sort<int> s;

  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    s.quickSort(input.data(), state.range(0));
  }
}

static void BM_stlqsort(benchmark::State& state) {
  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    std::sort(input.begin(), input.begin() + state.range(0));
  }
}

static void BM_boostqsort(benchmark::State& state) {
  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    boost::sort::pdqsort(input.begin(), input.begin() + state.range(0));
  }
}

static void BM_stlstable(benchmark::State& state) {
  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    std::stable_sort(input.begin(), input.begin() + state.range(0));
  }
}

static void BM_spinsort(benchmark::State& state) {
  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    boost::sort::spinsort(input.begin(), input.begin() + state.range(0));
  }
}

static void BM_samplesort(benchmark::State& state) {
  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    boost::sort::sample_sort(input.begin(), input.begin() + state.range(0));
  }
}

static void BM_spreadsort(benchmark::State& state) {
  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    boost::sort::spreadsort::spreadsort(input.begin(), input.begin() + state.range(0));
  }
}

static void BM_blockindirectsort(benchmark::State& state) {
  for (auto _ : state)
  {
    state.PauseTiming();
    for (auto i = 0; i < state.range(0); i++)
      input[i] = getRandomNumber();
    state.ResumeTiming();
    boost::sort::block_indirect_sort(input.begin(), input.begin() + state.range(0));
  }
}

BENCHMARK(BM_mergesort)->Range(1000, SIZE);
BENCHMARK(BM_radixsort)->Range(1000, SIZE);
BENCHMARK(BM_quicksort)->Range(1000, SIZE);
BENCHMARK(BM_stlqsort)->Range(1000, SIZE);
BENCHMARK(BM_spreadsort)->Range(1000, SIZE);
BENCHMARK(BM_boostqsort)->Range(1000, SIZE);
BENCHMARK(BM_stlstable)->Range(1000, SIZE);
BENCHMARK(BM_spinsort)->Range(1000, SIZE)->UseRealTime();
BENCHMARK(BM_blockindirectsort)->Range(1000, SIZE)->UseRealTime();
BENCHMARK(BM_samplesort)->Range(1000, SIZE)->UseRealTime();


BENCHMARK_MAIN();