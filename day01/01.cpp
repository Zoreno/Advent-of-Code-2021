#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

std::vector<int> ReadNumbersFromFile(const char *path)
{
  std::ifstream input(path);

  if (!input.is_open()) {
    std::cout << "Could not open file " << path << std::endl;
    return {};
  }

  std::string line;
  std::vector<int> result;

  while (std::getline(input, line)) {
    result.push_back(std::stoi(line));
  }

  return result;
}

int CalculateIncreases(const std::vector<int> &numbers)
{
  int increases = 0;
  int last = std::numeric_limits<int>::max();

  for (int i = 0; i < numbers.size(); ++i) {
    if (numbers[i] > last) {
      increases++;
    }
    last = numbers[i];
  }

  return increases;
}

int main(int argc, const char **argv)
{
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <data file>" << std::endl;
    return 1;
  }

  std::vector<int> numbers = ReadNumbersFromFile(argv[1]);
  int increases = CalculateIncreases(numbers);
  std::cout << "Increases: " << increases << std::endl;
}
