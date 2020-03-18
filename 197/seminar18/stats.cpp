#include <future>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Stats {
  std::map<string, int> word_frequences;

  void operator+=(const Stats &other) {
    for (const auto &[key, value] : other.word_frequences) {
      word_frequences[key] += value;
    }
  }
};

Stats ExploreLine(const std::set<string> &key_words, const string &line) {
  Stats stats;
  std::string word;
  std::stringstream ss{line};
  while (!ss.eof()) {
    ss >> word;
    if (key_words.find(word) != key_words.end())
      stats.word_frequences[word] += 1;
  }
  return stats;
}

Stats ExploreKeyWordsSingleThread(const std::set<string> &key_words,
                                  istream &input) {
  Stats result;
  for (string line; std::getline(input, line);) {
    result += ExploreLine(key_words, line);
  }
  return result;
}

Stats ExploreKeyWords(const std::set<string> &key_words, istream &input) {
  Stats result;
  std::vector<std::future<Stats>> futures;
  for (string line; std::getline(input, line);) {
    futures.push_back(
        std::async(ExploreLine, std::ref(key_words), std::ref(line)));
  }
  for (auto&& fut : futures) {
    result += fut.get();
  }
  return result;
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
  const map<string, int> expected = {{"yandex", 6}, {"rocks", 2}, {"sucks", 1}};
  assert(stats.word_frequences == expected);
}

int main() { TestBasic(); }