// g++ 050205.cc -o 050205

#include <time.h>
#include <iostream>
using namespace std;

#include <boost/format.hpp>
using namespace boost;

void case3()
{
    time_t start = time(0);
    for (int i = 0; i < 2000000; i++) {
        format fmt("%10d %020.8f %010X %10.5e\n");
        fmt % 62 % 2.236 % 48 % 123456789;
    }
    cout << time(0) - start << endl;
    cout << endl;

    start = time(0);
    const format const_fmt("%10d %020.8f %010X %10.5e\n");
    for (int i = 0; i < 2000000; i++) {
        format fmt(const_fmt);
        fmt % 62 % 2.236 % 48 % 123456789;
    }
    cout << time(0) - start << endl;
}

int main()
{
    case3();

    return 0;
}

