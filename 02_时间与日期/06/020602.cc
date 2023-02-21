// g++ 020602.cc -o 020602

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

void case1()
{
    {
        time_duration td = duration_from_string("1:10:30:001");
        cout << td << endl;

        time_duration td1(1, 10, 30, 1000);
        time_duration td2(1, 60, 60, 1000 * 1000 * 6 + 1000);
        cout << td1 << ", " << td2 << endl;
    }

    hours h(1);
    minutes m(10);
    seconds s(30);
    millisec ms(1);

    time_duration td = h + m + s + ms;
    time_duration td2 = hours(2) + seconds(10);

    cout << td << ", " << td2 << endl;
    cout << endl;
}

void case2()
{
    time_duration td(1, 10, 30, 1000);
    assert(td.hours() == 1 && td.minutes() == 10 && td.seconds() == 30);
    assert(td.total_seconds() == 1 * 3600 + 10 * 60 + 30);
    cout << td << endl;

#ifndef BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG
    assert(td.total_milliseconds() == td.total_seconds() * 1000 + 1);
    assert(td.fractional_seconds() == 1000);
#endif

    hours h(-10);
    assert(h.is_negative());
    cout << h << endl;

    time_duration h2 = h.invert_sign();
    assert(!h2.is_negative() && h2.hours() == 10);
    cout << h2 << endl;

    time_duration td1(not_a_date_time);
    assert(td1.is_special() && td1.is_not_a_date_time());
    cout << td1 << endl;

    time_duration td2(neg_infin);
    assert(td2.is_negative() && td2.is_neg_infinity());
    cout << td2 << endl;
    cout << endl;
}

void case3()
{
    time_duration td1 = hours(1);
    time_duration td2 = hours(2) + minutes(30);
    assert(td1 < td2);
    assert((td1 + td2).hours() == 3);
    assert((td1 - td2).is_negative());
    assert(td1 * 5 == td2 * 2);
    assert((td1 / 2).minutes() == td2.minutes());

    time_duration td(1, 10, 30, 1000);
    cout << to_simple_string(td) << endl;
    cout << to_iso_string(td) << endl;
}

int main()
{
    case1();
    case2();
    case3();

    return 0;
}

