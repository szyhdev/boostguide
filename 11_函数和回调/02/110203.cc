// g++ 110203.cc -o 110203

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <boost/bind/bind.hpp>
using namespace boost;
using namespace boost::placeholders;

struct demo {
    int f(int a, int b) {
        return a + b;
    }
};

struct point {
    int x;
    int y;
    point(int a = 0, int b = 1) : x(a), y(b) {
    }
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    demo a;
    demo& ra = a;
    demo* pa = &a;
    cout << bind(&demo::f, a, _1, 20)(10) << endl;
    cout << bind(&demo::f, ra, _2, _1)(10, 20) << endl;
    cout << bind(&demo::f, pa, _1, _2)(10, 20) << endl;
    cout << endl;

    vector<point> v(5);
    for_each(v.begin(), v.end(), bind(&point::print, _1));

    return 0;
}

