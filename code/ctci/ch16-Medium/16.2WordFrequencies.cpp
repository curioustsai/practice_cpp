#include <gtest/gtest.h>
#include <map>
#include <string>

// Word Frequencies in a book

using namespace std;
int countFrequency(string word, vector<string> book) {
    int count = 0;
    for (string &w : book) {
        if (word == w) count++;
    }
    return count;
}

TEST(Medium, countFrequency) {
    vector<string> book = {"richard", "super", "handsome", "richard"};
    int res = countFrequency("richard", book);

    ASSERT_EQ(res, 2);
}

class solution {
public:
    void parse(vector<string> book) {
        for (string &w : book) {
            auto search = dict.find(w);
            if (search == dict.end()) {
                dict.insert(std::pair<string, int>(w, 1));
            } else {
                search->second += 1;
            }
        }
    }

    int query(const string &word) {
        auto search = dict.find(word);
        return (search == dict.end()) ? 0 : search->second;
    }

private:
    map<string, int> dict;
};

class SolutionTest : public testing::Test {
protected:
    void SetUp() override {
        book = {"Richard", "richard", "Richard", "cool", "bad", "smart", "smart"};
    }

    void TearDown() override {}

    vector<string> book;
    solution sol;
};

TEST_F(SolutionTest, MultipleQuery) {
    sol.parse(book);
    ASSERT_EQ(sol.query("Richard"), 2);
    ASSERT_EQ(sol.query("richard"), 1);
    ASSERT_EQ(sol.query("smart"), 2);
    ASSERT_EQ(sol.query("Alan"), 0);
}
