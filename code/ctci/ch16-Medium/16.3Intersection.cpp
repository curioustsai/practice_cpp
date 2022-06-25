#include <gtest/gtest.h>
#include <string>

// check intersection

using namespace std;

struct Point {
    float x;
    float y;

    Point(float xx, float yy) : x(xx), y(yy) {}
};

class Line {
public:
    Line(Point pp, Point qq) : p(pp), q(qq) {
        slope = (p.x - q.x) / (p.y - q.y);
        // y = slope * x + offset
        offset = p.y - slope * p.x;
    }

    bool intersection(Line l2) {

        bool sign_p = sign(slope * l2.p.x + offset - l2.p.y);
        bool sign_q = sign(slope * l2.q.x + offset - l2.q.y);

        return (sign_p == sign_q) ? false : true;
    }

private:
    template <typename T>
    inline bool sign(T x) {
        return (x > 0) ? 1 : 0;
    }
    Point p;
    Point q;

    float slope;
    float offset;
};

TEST(Medium, LineIntersection) {
    Point p1(2, 2), q1(4, 4);
    Point p2(1, -1), q2(4, 5);

    Line line1(p1, q1);
    Line line2(p2, q2);

    ASSERT_EQ(true, line1.intersection(line2));
}
