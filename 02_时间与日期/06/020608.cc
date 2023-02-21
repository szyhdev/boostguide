// g++ 020608.cc -o 020608

#include <iostream>
using namespace std;

#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

void case8()
{
    ptime p(date(2017, 1, 1), hours(12)) ;
    time_period tp1(p, hours(8));
    time_period tp2(p + hours(8), hours(1));
    assert(tp1.end() == tp2.begin() && tp1.is_adjacent(tp2));
    assert(!tp1.intersects(tp2));

    tp1.shift(hours(1));
    assert(tp1.is_after(p));
    assert(tp1.intersects(tp2));

    tp2.expand(hours(10));
    assert(tp2.contains(p) && tp2.contains(tp1));
}

int main()
{
    case8();

    return 0;
}

