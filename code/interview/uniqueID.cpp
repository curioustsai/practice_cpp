#include <iostream>
#include <cstdlib>
#include <unordered_set>

using namespace std;

class Solution {
public:
  string uniqueID() {
    string result = "";

    while (true) {
      char c = randomCharacter();
      if (result.size() <= 2) {
        result += c;
        continue;
      } 

      int size = result.size();
      if (c == result[size - 2] && c == result[size - 1]) {
        break;
      }
      result += c;
    }

    if (log.find(result) != log.end()) 
      return uniqueID();

    log.insert(result);
    return result;
  }

private:
  char randomCharacter() {
    char c;
    do {
      c = rand() % 128;
    } while (!isprint(c));

    return c;
  }
  unordered_set<string> log;
};

//int main (int argc, char *argv[])
int main() {
  Solution sol;

  std::cout << sol.uniqueID() << std::endl;
  std::cout << sol.uniqueID() << std::endl;
  std::cout << sol.uniqueID() << std::endl;
  std::cout << sol.uniqueID() << std::endl;

  return 0;
}
