// g++ 020506.cc -o 020506

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case7()
{
    days dd1(10), dd2(-100), dd3(255);

    assert(dd1 > dd2 && dd1 < dd3);
    assert(dd1 + dd2 == days(-90));
    assert((dd1 + dd3).days() == 265);
    assert(dd3 / 5 == days(51));

    weeks w(3);
    assert(w.days() == 21);

    months m(5);
    years y(2);
    months m2 = y + m;
    assert(m2.number_of_months() == 29);
    assert((y * 2).number_of_years() == 4);
}

int main() {
    case7();

    return 0;
}

