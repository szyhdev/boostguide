// g++ 020603.cc -o 020603

#include <iostream>
using namespace std;

#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

void case4()
{
#ifdef BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG
    time_duration td(1, 10, 30, 1000);
    cout << td << endl;
    assert(td.total_milliseconds() == td.total_seconds() * 1000);

    assert(td.fractional_seconds() == 1000);
    assert(time_duration::unit() * 1000 * 1000 * 1000 == seconds(1));

    assert(td.resolution() == boost::date_time::nano);
    assert(td.num_fractional_digits() == 9);
#endif
}

int main()
{
    case4();

    return 0;
}

