// g++ 020606.cc -o 020606

#include <iostream>
using namespace std;

#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

void case6()
{
    ptime p(date(2010, 3, 20), hours(12) + minutes(30));

    date d = p.date();
    time_duration td = p.time_of_day();
    assert(d.month() == 3 && d.day() == 20);
    assert(td.total_seconds() == 12 * 3600 + 30 * 60);

    ptime p1(date(2010, 3, 20), hours(12) + minutes(30));
    ptime p2 = p1 + hours(3);

    assert(p1 < p2);
    assert(p2 - p1 == hours(3));
    p2 += months(1);
    assert(p2.date().month() == 4);

    {
        ptime p(date(2017, 2, 14), hours(20));
        cout << to_simple_string(p) << endl;
        cout << to_iso_string(p) << endl;
        cout << to_iso_extended_string(p) << endl;
    }
}

int main()
{
    case6();

    return 0;
}

