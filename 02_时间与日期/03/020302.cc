// g++ 020302.cc -o 020302

#include <iostream>
#include <sstream>
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
    stringstream ss;
    {
        progress_timer pt(ss);
        do_work();
    }
    cout << ss.str();

    return 0;
}

