// g++ 020607.cc -o 020607

#include <iostream>
using namespace std;

#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

void case7()
{
    ptime p(date(2017, 5, 20), hours(14));
    tm t = to_tm(p);
    assert(t.tm_year == 117 && t.tm_hour == 14);
    assert(ptime_from_tm(t) == p);

    ptime p2 = from_time_t(std::time(0));
    assert(p2.date() == day_clock::local_day());
    cout << to_time_t(p2) << endl;
}

int main()
{
    case7();

    return 0;
}

