// g++ 020301.cc -o 020301

#include <iostream>
using namespace std;

// disable pragma warning
#define BOOST_ALLOW_DEPRECATED_HEADERS

#include <boost/progress.hpp>
using namespace boost;

void do_work() {
    int sum = 0;
    for (int i = 0; i < 100000000; i++) {
        int x = i * i;
        sum += x;
    }
}

int main() {
    {
        progress_timer t;
        do_work();
    }

    {
        progress_timer t;
        do_work();
    }
 
    return 0;
}

