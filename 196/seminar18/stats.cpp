#include <map>
#include <string>
#include <set>
#include <sstream>

using namespace std;

struct Stats {
  unordered_map<string, int> word_frequences;

  void operator += (const Stats& other);
};

Stats ExploreLine(const std::set<string>& key_words, const string& line) {
  // std::string_view
}

Stats ExploreKeyWordsSingleThread(
    const std::set<string>& key_words, istream& input
) {
  Stats result;
  for (string line; std::getline(input, line); ) {
    result += ExploreLine(key_words, line);
  }
  return result;
}

Stats ExploreKeyWords(const std::set<string>& key_words, istream& input) {
}

void TestBasic() {
  const std::set<string> key_words = {"yandex", "rocks", "sucks", "all"};

  std::stringstream ss;
  ss << "this new yandex service really rocks\n";
  ss << "It sucks when yandex isn't available\n";
  ss << "10 reasons why yandex is the best IT company\n";
  ss << "yandex rocks others suck\n";
  ss << "Gogle really sucks, but yandex rocks. Use yandex\n";

  const auto stats = ExploreKeyWords(key_words, ss);
  const map<string, int> expected = {
      {"yandex", 6},
      {"rocks", 2},
      {"sucks", 1}
  };
  assert(stats.word_frequences == expected);
}

int main() {
  TestBasic();
}