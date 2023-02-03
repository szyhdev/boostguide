// g++ 110205.cc -o 110205

#include <iostream>
using namespace std;

#include <boost/bind/bind.hpp>
using namespace boost;
using namespace boost::placeholders;

struct func {
    int operator ()(int a, int b) {
        return a + b;
    }
};

int main() {
    cout << bind(greater<int>(), _1, 10)(20) << endl;
    cout << bind(plus<int>(), _1, _2)(10, 20) << endl;
    cout << bind(modulus<int>(), _1, 3)(20) << endl;
    cout << endl;

    cout << bind<int>(func(), _1, _2)(1, 2) << endl;

    return 0;
}

