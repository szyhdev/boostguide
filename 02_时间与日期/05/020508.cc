// g++ 020508.cc -o 020508

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case9()
{
    date_period dp1(date(2017, 1, 1), days(20));
    date_period dp2(date(2017, 1, 1), date(2016, 1, 1));
    date_period dp3(date(2017, 3, 1), days(-20));
    cout << dp3 << endl;
    date_period dp(date(2017, 1, 1), days(20));

    assert(!dp.is_null());
    assert(dp.begin().day() == 1);
    assert(dp.last().day() == 20);
    assert(dp.end().day() == 21);
    assert(dp.length().days() == 20);

    {
        date_period dp1(date(2017, 1, 1), days(20));
        date_period dp2(date(2017, 2, 19), days(10));
        cout << dp1 << endl;
        assert(dp1 < dp2);
    }
}

int main() {
    case9();

    return 0;
}

