#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::pair<std::string, int>> ReadInstructionsFromFile(const char *path)
{
  std::ifstream input(path);

  if (!input.is_open()) {
    std::cout << "Could not open file " << path << std::endl;
    return {};
  }

  std::string line;
  std::vector<std::pair<std::string, int>> result;

  while (std::getline(input, line)) {
    std::istringstream iss(line);
    std::string instruction;
    int value;
    iss >> instruction >> value;
    result.push_back({instruction, value});
  }

  return result;
}

int main(int argc, const char **argv)
{
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <data file>" << std::endl;
    return 1;
  }

  auto instructions = ReadInstructionsFromFile(argv[1]);
  int hpos = 0;
  int depth = 0;

  for (auto &[instruction, value] : instructions) {
    if (instruction == "forward") {
      hpos += value;
    }

    if (instruction == "down") {
      depth += value;
    }

    if (instruction == "up") {
      depth -= value;
    }
  }

  std::cout << "Final position: " << hpos << "," << depth << std::endl;
  std::cout << "Product: " << hpos * depth << std::endl;
}
