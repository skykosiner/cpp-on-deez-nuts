#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int part_one() {
  ifstream infile("./day-one.input");

  if (!infile) {
    cout << "it's joever\n";
    return -1;
  }

  string line;
}

int main() {
  std::cout << part_one() << "\n";
  return 0;
}
