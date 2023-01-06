// g++ 040602.cc -o 040602

#include <iostream>
#include <cassert>
using namespace std;

#include <boost/operators.hpp>
using namespace boost;

class point : less_than_comparable<point>, equality_comparable<point>
{
    int x, y, z;
public:
    explicit point(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {
    }
    void print() const {
        cout << x << ", " << y << ", " << z << endl;
    }
    friend bool operator <(const point& l, const point& r) {
        return (l.x * l.x + l.y * l.y + l.z * l.z <
                r.x * r.x + r.y * r.y + r.z * r.z);
    }
    friend bool operator ==(const point& l, const point& r) {
        return r.x == l.x && r.y == l.y && r.z == l.z;
    }
};

void case2()
{
    point p0, p1(1, 2, 3), p2(3, 0, 5), p3(3, 2, 1);
    assert(p0 < p1 && p1 < p2);
    assert(p2 > p0);
    assert(p1 <= p3);
    assert(!(p1 < p3) && !(p1 > p3));

    {
        point p0, p1(1, 2, 3), p2(p1), p3(3, 2, 1);
        assert(p1 == p2);
        assert(p1 != p3);
    }
}

int main() {
    case2();

    return 0;
}

