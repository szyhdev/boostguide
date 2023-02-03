// g++ 110204.cc -o 110204

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <boost/bind/bind.hpp>
using namespace boost;
using namespace boost::placeholders;

struct point {
    int x;
    int y;
    point(int a = 0, int b = 1) : x(a), y(b) {
    }
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

typedef pair<int, string> pair_t;

int main() {
    vector<point> v(5);
    vector<int> v2(5);
    transform(v.begin(), v.end(), v2.begin(), bind(&point::y, _1));
    for (auto y: v2) {
        cout << y << " ";
    }
    cout << endl << endl;

    pair_t p(123, "string");
    cout << bind(&pair_t::first, p)() << endl;
    cout << bind(&pair_t::second, p)() << endl;

    return 0;
}

