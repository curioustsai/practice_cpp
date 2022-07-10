/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/

#include <gtest/gtest.h>

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {}
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();

        if (small.size() < large.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() + large.top()) / 2.0;
    }

private:
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;
};

TEST(MedianFinder, Example1) {
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> large;

    small.push(4);
    small.push(3);
    small.push(5);

    large.push(3);
    large.push(5);
    large.push(6);
}
