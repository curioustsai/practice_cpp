#include <gtest/gtest.h>

using namespace std;

struct People {
    int birth;
    int death;

    People(int b, int d) : birth(b), death(d){};
};

int FindMostPeopleYear(vector<People> group) {
    int hist[101] = {0};
    for (auto& people : group) {
        for (int i = people.birth; i <= people.death; i++) { hist[i - 1900]++; }
    }

    int max = 0;
    int max_year = 0;
    for (int i = 0; i <= 100; i++) {
        if (hist[i] > max) {
            max = hist[i];
            max_year = i;
        }
    }
    return max_year + 1900;
}

TEST(Medium, FindMostPeopleYear) {
    People a(1900, 1911), b(1900, 1920), c(1960, 2000), d{1911, 1911};
    vector<People> group;
    group.push_back(a);
    group.push_back(b);
    group.push_back(c);
    group.push_back(d);

    ASSERT_EQ(FindMostPeopleYear(group), 1911);
}
