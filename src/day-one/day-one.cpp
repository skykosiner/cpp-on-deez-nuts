#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int combine_items(char x, char y) {
  std::string string_deez_nuts = std::string(1, x) + std::string(1, y);
  return std::stoi(string_deez_nuts);
}

int part_one(std::ifstream &infile) {
  std::string line;
  std::vector<int> numbers;
  int sum = 0;

  while (std::getline(infile, line)) {
    std::vector<char> nums;
    for (char &c : line) {
      if (std::isdigit(c)) {
        nums.push_back(c);
      }
    }

    if (nums.size() > 2) {
      numbers.push_back(combine_items(nums[0], nums[nums.size() - 1]));
    } else if (nums.size() == 1) {
      numbers.push_back(combine_items(nums[0], nums[0]));
    } else {
      numbers.push_back(combine_items(nums[0], nums[1]));
    }
  }

  for (int num : numbers) {
    sum += num;
  }

  return sum;
}

int part_two(std::ifstream &infile) {
  std::string line;
  std::vector<int> numbers;
  std::vector<char> nums;
  std::unordered_map<std::string, int> map_deez_nuts{
      {"one", 1}, {"two", 2},   {"three", 3}, {"four", 4}, {"five", 5},
      {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

  int sum = 0;

  while (std::getline(infile, line)) {
    for (char &c : line) {
      if (std::isdigit(c)) {
        nums.push_back(c);
      }
    }
  }

  return sum;
}

int main() {
  std::ifstream infile("./day-one.input");

  if (!infile) {
    std::cout << "it's joever\n";
    return -1;
  }

  std::cout << part_one(infile) << "\n";

  return 0;
}
