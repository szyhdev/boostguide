// g++ 020201.cc -o 020201

#include <iostream>
using namespace std;

// disable pragma warning
#define BOOST_ALLOW_DEPRECATED_HEADERS

#include <boost/timer.hpp>
using namespace boost;

int main() {
    timer t;
    cout << CLOCKS_PER_SEC << endl;
    cout << "max timespan: " << t.elapsed_max() / 3600 << "h" << endl;
    cout << "min timespan: " << t.elapsed_min() << "s" << endl;
    cout << "now time elapsed: " << t.elapsed() << "s" << endl;

    return 0;
}

