// g++ 020509.cc -o 020509

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case1()
{
    date_period dp(date(2017, 1, 1), days(20));

    dp.shift(days(3));
    assert(dp.begin().day() == 4);
    assert(dp.length().days() == 20);

    dp.expand(days(3));
    assert(dp.begin().day() == 1);
    assert(dp.length().days() == 26);
}

void case2()
{
    date_period dp(date(2010, 1, 1), days(20));

    assert(dp.is_after(date(2009, 12, 1)));
    assert(dp.is_before(date(2010, 2, 1)));
    assert(dp.contains(date(2010, 1, 10)));

    date_period dp2(date(2010, 1, 5), days(10));
    assert(dp.contains(dp2));

    assert(dp.intersects(dp2));
    assert(dp.intersection(dp2) == dp2);

    date_period dp3(date(2010, 1, 21), days(5));
    assert(!dp3.intersects(dp2));
    assert(dp3.intersection(dp2).is_null());

    assert(dp.is_adjacent(dp3));
    assert(!dp.intersects(dp3));
}

void case3()
{
    date_period dp1(date(2010, 1, 1), days(20));
    date_period dp2(date(2010, 1, 5), days(10));
    date_period dp3(date(2010, 2, 1), days(5));
    date_period dp4(date(2010, 1, 15), days(10));

    assert(dp1.contains(dp2) && dp1.merge(dp2) == dp1);
    assert(!dp1.intersects(dp3) && dp1.merge(dp3).is_null());
    assert(dp1.intersects(dp2) && dp1.merge(dp4).end() == dp4.end());
    assert(dp1.span(dp3).end() == dp3.end());
}

int main()
{
    case1();
    case2();
    case3();

    return 0;
}

