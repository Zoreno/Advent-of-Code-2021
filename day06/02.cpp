#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, const char **argv)
{
  int daysToRun = argc > 1 ? std::stoi(argv[1]) : 80;

  std::vector<int> fishes = {4, 3, 4, 5, 2, 1, 1, 5, 5, 3, 3, 1, 5, 1, 4, 2, 2, 3, 1, 5, 1, 4, 1, 2, 3, 4, 1, 4, 1, 5, 2, 1, 1, 3, 3, 5, 1, 1, 1, 1, 4, 5, 1, 2, 1, 2, 1, 1, 1, 5, 3, 3, 1, 1, 1, 1, 2, 4, 2, 1, 2, 3, 2, 5, 3, 5, 3, 1, 5, 4, 5, 4, 4, 4, 1, 1, 2, 1, 3, 1, 1, 4, 2, 1, 2, 1, 2, 5, 4, 2, 4, 2, 2, 4, 2, 2, 5, 1, 2, 1, 2, 1, 4, 4, 4, 3, 2, 1, 2, 4, 3, 5, 1, 1, 3, 4, 2, 3, 3, 5, 3, 1, 4, 1, 1, 1, 1, 2, 3, 2, 1, 1, 5, 5, 1, 5, 2, 1, 4, 4, 4, 3, 2, 2, 1, 2, 1, 5, 1, 4, 4, 1, 1, 4, 1, 4, 2, 4, 3, 1, 4, 1, 4, 2, 1, 5, 1, 1, 1, 3, 2, 4, 1, 1, 4, 1, 4, 3, 1, 5, 3, 3, 3, 4, 1, 1, 3, 1, 3, 4, 1, 4, 5, 1, 4, 1, 2, 2, 1, 3, 3, 5, 3, 2, 5, 1, 1, 5, 1, 5, 1, 4, 4, 3, 1, 5, 5, 2, 2, 4, 1, 1, 2, 1, 2, 1, 4, 3, 5, 5, 2, 3, 4, 1, 4, 2, 4, 4, 1, 4, 1, 1, 4, 2, 4, 1, 2, 1, 1, 1, 1, 1, 1, 3, 1, 3, 3, 1, 1, 1, 1, 3, 2, 3, 5, 4, 2, 4, 3, 1, 5, 3, 1, 1, 1, 2, 1, 4, 4, 5, 1, 5, 1, 1, 1, 2, 2, 4, 1, 4, 5, 2, 4, 5, 2, 2, 2, 5, 4, 4};

  std::vector<uint64_t> fishCounts;
  fishCounts.resize(9);

  for (auto fish : fishes) {
    fishCounts[fish]++;
  }

  for (int day = 0; day < daysToRun; ++day) {
    uint64_t newFishes = fishCounts[0];
    std::copy(fishCounts.begin() + 1, fishCounts.end(), fishCounts.begin());
    fishCounts[6] += newFishes;
    fishCounts[8] = newFishes;
    std::cout << "Day " << day + 1 << ": " << std::accumulate(fishCounts.begin(), fishCounts.end(), 0ULL) << std::endl;
  }
}
