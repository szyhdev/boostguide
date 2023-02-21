// g++ 020609.cc -o 020609

#include <iostream>
using namespace std;

#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

void case9()
{
    ptime p(date(2017, 5, 31), hours(10));
    for (time_iterator t_iter(p, minutes(10)); t_iter < p + hours(1); ++t_iter) {
        cout << *t_iter << endl;
    }
}

int main()
{
    case9();

    return 0;
}

