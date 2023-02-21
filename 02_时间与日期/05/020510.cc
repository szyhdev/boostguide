// g++ 020510.cc -o 020510

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case4()
{
    date d(2007, 9, 28);
    day_iterator d_iter(d);

    assert(d_iter == d);
    ++d_iter;
    assert(d_iter == date(2007, 9, 29));

    year_iterator y_iter(*d_iter, 10);
    assert(y_iter == d + days(1));
    ++y_iter;
    assert(y_iter->year() == 2017);

    day_iterator iter(day_clock::local_day());
    ++iter;

    // iter += 5;  // Compile error
    // std::advance(iter, 5);  // Compile error
}

int main()
{
    case4();

    return 0;
}

