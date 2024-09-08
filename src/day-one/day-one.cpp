#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int combine_items(char x, char y) {
  string string_deez_nuts = string(1, x) + string(1, y);
  return stoi(string_deez_nuts);
}

bool replace(string &str, const string &from, const string &to) {
  size_t start_pos = str.find(from);
  if (start_pos == string::npos)
    return false;
  str.replace(start_pos, from.length(), to);
  return true;
}

int part_one() {
  ifstream infile("./day-one.input");

  if (!infile) {
    cout << "it's joever\n";
    return -1;
  }

  string line;
  vector<int> numbers;
  int sum = 0;

  while (getline(infile, line)) {
    vector<char> nums;
    for (char &c : line) {
      if (isdigit(c)) {
        nums.push_back(c);
      }
    }

    numbers.push_back(combine_items(nums[0], nums[nums.size() - 1]));
  }

  for (int num : numbers) {
    sum += num;
  }

  return sum;
}

int part_two() {
  ifstream infile("./day-one-test-two.input");

  if (!infile) {
    cout << "it's joever\n";
    return -1;
  }

  string line;
  vector<int> numbers;
  unordered_map<string, string> map_deez_nuts{
      {"one", "one1one"},       {"two", "two2two"},
      {"three", "three3three"}, {"four", "four4four"},
      {"five", "five5five"},    {"six", "six6six"},
      {"seven", "seven7seven"}, {"eight", "eight8eight"},
      {"nine", "nine9nine"}};

  int sum = 0;

  while (getline(infile, line)) {
    vector<char> nums;
    for (const auto &item : map_deez_nuts) {
      replace(line, item.first, item.second);
    }

    for (char &c : line) {
      if (isdigit(c)) {
        nums.push_back(c);
      }
    }

    numbers.push_back(combine_items(nums[0], nums[nums.size() - 1]));
  }

  for (int num : numbers) {
    sum += num;
  }

  return sum;
}

int main() {
  cout << part_one() << "\n";
  cout << part_two() << "\n";

  return 0;
}
