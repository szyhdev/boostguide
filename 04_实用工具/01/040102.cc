// g++ 040102.cc -o 040102

#include <iostream>
using namespace std;

#include <boost/noncopyable.hpp>
using namespace boost;

class do_not_copy : noncopyable {
};

int main() {
    do_not_copy d1;
    // do_not_copy d2 = d1;  // Compile error
    do_not_copy d3;
    // d3 = d1;  // Compile error

    return 0;
}

