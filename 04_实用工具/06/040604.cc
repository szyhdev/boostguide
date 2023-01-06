// g++ 040604.cc -o 040604

#include <iostream>
#include <cassert>
using namespace std;

#include <boost/operators.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;

class point : totally_ordered<point, additive<point>>
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
    point& operator +=(const point& r) {
        x += r.x;
        y += r.y;
        z += r.z;
        return *this;
    }
    point& operator -=(const point& r) {
        x -= r.x;
        y -= r.y;
        z -= r.z;
        return *this;
    }
};

void case3()
{
    point p0, p1(1, 2, 3), p2(5, 6, 7), p3(3, 2, 1);

    vector<point> v = (list_of(p0), p1, p2, p3);

    auto pos = find(v.begin(), v.end(), point(1, 2, 3));
    pos->print();

    (p1 + p2).print();
    (p3 - p1).print();

    assert((p2 - p2) == p0);
}

int main() {
    case3();

    return 0;
}

