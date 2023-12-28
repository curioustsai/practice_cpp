/*
 * You are given a stream of points on the X-Y plane. Design an algorithm that:
 * Adds new points from the stream into a data structure. Duplicate points are allowed and should be treated as different points. 
 * Given a query point, counts the number of ways to choose three points from the data structure such that the three points and the query point form an axis-aligned square with positive area. 
 * An axis-aligned square is a square whose edges are all the same length and are either parallel or perpendicular to the x-axis and y-axis.
 *
 * Implement the DetectSquares class: 
 *
 * DetectSquares() Initializes the object with an empty data structure. 
 * void add(int[] point) Adds a new point point = [x, y] to the data structure. 
 * int count(int[] point) Counts the number of ways to form axis-aligned squares with point point = [x, y] as described
 *
 * https://leetcode.com/problems/detect-squares/description/
 */
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class DetectSquares {
public:
    DetectSquares() {}

    void add(vector<int> point) { points[point[0]][point[1]]++; }

    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int result = 0;

        for (auto x = points.begin(); x != points.end(); x++) {
            unordered_map<int, int> yPoints = x->second;
            for (auto y = yPoints.begin(); y != yPoints.end(); y++) {
                int x3 = x->first;
                int y3 = y->first;

                if (abs(x3 - x1) == 0 || abs(x3 - x1) != abs(y3 - y1)) continue;

                result += points[x3][y3] * points[x3][y1] * points[x1][y3];
            }
        }
        return result;
    }

private:
    // x -> {y -> count}
    unordered_map<int, unordered_map<int, int>> points;
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
