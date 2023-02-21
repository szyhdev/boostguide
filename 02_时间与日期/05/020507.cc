// g++ 020507.cc -o 020507

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case8()
{
    date d1(2000, 1, 1), d2(2017, 11, 18);
    cout << d2 - d1 << endl;
    assert(d1 + (d2 - d1) == d2);

    d1 += days(10);
    assert(d1.day() == 11);
    d1 += months(2);
    assert(d1.month() == 3 && d1.day() == 11);
    d1 -= weeks(1);
    assert(d1.day() == 4);

    d2 -= years(10);
    assert(d2.year() == d1.year() + 7);

    {
        date d1(2017, 1, 1);
        date d2 = d1 + days(pos_infin);
        assert(d2.is_pos_infinity());

        d2 = d1 + days(not_a_date_time);
        assert(d2.is_not_a_date());

	d2 = date(neg_infin);
        days dd = d1 - d2;
        assert(dd.is_special() && !dd.is_negative());
    }

    {
        date d(2017, 7, 31);
        d -= months(1);
        d -= months(1);
        d += months(2);
        assert(d.day() == 31);
    }
}

int main() {
    case8();

    return 0;
}

