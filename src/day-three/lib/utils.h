#include <string>
#include <vector>

namespace utils {
std::vector<std::string> read_file(const std::string path);
std::vector<std::pair<int, int>> get_adj(int y, int x);
bool is_symbol(char c);
} // namespace utils
