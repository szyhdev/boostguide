// g++ 020505.cc -o 020505

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case6()
{
    date d(2017, 5, 20);
    cout << d << endl;
    tm t = to_tm(d);
    assert(t.tm_hour == 0 && t.tm_min == 0);
    assert(t.tm_year == 117 && t.tm_mday == 20);

    date d2 = date_from_tm(t);
    cout << d2 << endl;
    assert(d == d2);
}

int main() {
    case6();

    return 0;
}

