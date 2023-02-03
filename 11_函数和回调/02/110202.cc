// g++ 110202.cc -o 110202

#include <iostream>
using namespace std;

#include <boost/bind/bind.hpp>
using namespace boost;
using namespace boost::placeholders;

int f(int a, int b) {
    return a + b;
}

int g(int a, int b, int c) {
    return a + b * c;
}

typedef decltype(&f) f_type;
typedef decltype(&g) g_type;

int main() {
    cout << f(1, 2) << endl;
    cout << g(1, 2, 3) << endl;
    cout << bind(f, 1, 2)() << endl;
    cout << bind(g, 1, 2, 3)() << endl;
    cout << endl;

    int x = 10;
    int y = 20;
    int z = 30;
    cout << bind(f, _1, 9)(x) << endl;
    cout << bind(f, _1, _2)(x, y) << endl;
    cout << bind(f, _2, _1)(x, y) << endl;
    cout << bind(f, _1, _1)(x, y) << endl;
    cout << bind(g, _1, 8, _2)(x, y) << endl;
    cout << bind(g, _3, _2, _2)(x, y, z) << endl;
    cout << endl;

    f_type pf = f;
    g_type pg = g;
    cout << bind(pf, _1, 9)(x) << endl;
    cout << bind(pg, _3, _2, _2)(x, y, z) << endl;

    return 0;
}

