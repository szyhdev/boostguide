// g++ 040605.cc -o 040605

#include <iostream>
#include <cassert>
using namespace std;

#include <boost/operators.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;

class point1 : equality_comparable<point1>
{
    int x, y, z;
public:
    explicit point1(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {
    }
    void print() const {
        cout << x << ", " << y << ", " << z << endl;
    }
    friend bool operator ==(const point1& l, const point1& r) {
        return r.x == l.x && r.y == l.y && r.z == l.z;
    }
};

void case4_point1()
{
    point1 p0, p1(1, 2, 3), p2(5, 6, 7), p3(3, 2, 1);

    using namespace boost::assign;
    vector<point1> v = (list_of(p0), p1, p2, p3);

    auto pos = find(v.begin(), v.end(), point1(1, 2, 3));
    for (; pos != v.end(); pos = std::find(pos + 1, v.end(), point1(1, 2, 3))) {
        pos->print();
    }

    pos = find(v.begin(), v.end(), point1(2, 1, 3));
    assert(pos == v.end());
    cout << endl;
}

class point2 : equivalent<point2>
{
    int x, y, z;
public:
    explicit point2(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {
    }
    void print() const {
        cout << x << ", " << y << ", " << z << endl;
    }
    friend bool operator <(const point2& l, const point2& r) {
        return (l.x * l.x + l.y * l.y + l.z * l.z <
                r.x * r.x + r.y * r.y + r.z * r.z);
    }
};

void case4_point2()
{
    point2 p0, p1(1, 2, 3), p2(5, 6, 7), p3(3, 2, 1);

    using namespace boost::assign;
    vector<point2> v = (list_of(p0), p1, p2, p3);

    auto pos = find(v.begin(), v.end(), point2(1, 2, 3));
    for (; pos != v.end(); pos = std::find(pos + 1, v.end(), point2(1, 2, 3))) {   
        pos->print();
    }

    pos = find(v.begin(), v.end(), point2(2, 1, 3));
    assert(pos != v.end());
}

int main() {
    case4_point1();
    case4_point2();

    return 0;
}

