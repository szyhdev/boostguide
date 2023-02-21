// g++ 020503.cc -o 020503

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case4()
{
    date d(2017, 6, 1);
    assert(d.year() == 2017);
    assert(d.month() == 6);
    assert(d.day() == 1);

    date::ymd_type ymd = d.year_month_day();
    assert(ymd.year == 2017);
    assert(ymd.month == 6);
    assert(ymd.day == 1);

    cout << d.day_of_week() << endl;
    cout << d.day_of_year() << endl;
    assert(d.end_of_month() == date(2017, 6, 30));

    cout << date(2015, 1, 10).week_number() << endl;
    cout << date(2016, 1, 10).week_number() << endl;
    cout << date(2017, 1, 10).week_number() << endl;

    assert(date(pos_infin).is_infinity());
    assert(date(neg_infin).is_infinity());
    assert(date(pos_infin).is_pos_infinity());
    assert(date(neg_infin).is_neg_infinity());
    assert(date(not_a_date_time).is_not_a_date());
    assert(date(not_a_date_time).is_special());
    assert(!date(2017, 5, 31).is_special());
}

int main() {
    case4();

    return 0;
}

