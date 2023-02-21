// g++ 020605.cc -o 020605

#include <iostream>
using namespace std;

#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

void case5()
{
    ptime p(date(2017, 7, 7), hours(1));
    ptime p1 = time_from_string("2017-7-7 01:00:00");
    ptime p2 = from_iso_string("20170707T010000");
    cout << p1 << endl;
    cout << p2 << endl;

    {
        ptime p1 = second_clock::local_time();
        ptime p2 = microsec_clock::universal_time();
        cout << p1 << endl;
       	cout << p2 << endl;
    }

    {
        ptime p1(not_a_date_time);
        assert(p1.is_not_a_date_time());
        ptime p2(pos_infin);
        assert(p2.is_special() && p2.is_pos_infinity());
    }
}

int main()
{
    case5();

    return 0;
}

