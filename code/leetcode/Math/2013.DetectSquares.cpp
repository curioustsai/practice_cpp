/*
 * https://leetcode.com/problems/detect-squares/description/
 */
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int result = 0;

        for (auto x=points.begin(); x!=points.end(); x++) {
            unordered_map<int, int> yPoints = x->second;
            for (auto y=yPoints.begin(); y != yPoints.end(); y++) {
                int x3 = x->first;
                int y3 = y->first;

                if (abs(x3-x1) == 0 || abs(x3-x1) != abs(y3-y1))
                    continue;

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
