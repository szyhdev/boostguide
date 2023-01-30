// g++ 080401.cc -o 080401

#include <iostream>
using namespace std;

#include <boost/assert.hpp>
#include <boost/algorithm/clamp.hpp>
using namespace boost;
using namespace boost::algorithm;

void case1() {
    assert(clamp(5, 1, 10) == 5);
    assert(clamp(5, 5, 10) == 5);
    assert(clamp(5, 1, 5) == 5);
    assert(clamp(5, 10, 15) == 10);
    assert(clamp(5, 0, 4) == 4);
    cout << "clamp(5, 20, 10) = " << clamp(5, 20, 10) << endl;
    cout << "clamp(5, 4, 1) = " << clamp(5, 4, 1) << endl;
}

int main() {
    case1();

    return 0;
}

