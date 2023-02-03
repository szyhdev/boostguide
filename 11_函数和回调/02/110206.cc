// g++ 110206.cc -o 110206

#include <iostream>
#include <functional>
using namespace std;

#include <boost/bind/bind.hpp>
using namespace boost;
using namespace boost::placeholders;

int f(int a, int b) {
    return a + b;
}

int main() {
    cout << boost::bind(f, _1, _2)(10, 20) << endl;
    cout << std::bind(f, std::placeholders::_1, std::placeholders::_2)(10, 20) << endl;
    cout << endl;

    auto lf = [] (int x) {
        return f(x, 20);
    };
    cout << lf(10) << endl;
    cout << bind(f, _1, 20)(10) << endl;

    return 0;
}

