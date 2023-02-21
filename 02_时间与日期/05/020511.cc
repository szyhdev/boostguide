// g++ 020511.cc -o 020511

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case5()
{
    typedef gregorian_calendar gre_cal;
    cout << "Y2017 is" << (gre_cal::is_leap_year(2017)? " " : " not ") <<
            "a leap year." << endl;
    assert(gre_cal::end_of_month_day(2017, 2) == 28);
}

int main()
{
    case5();

    return 0;
}

