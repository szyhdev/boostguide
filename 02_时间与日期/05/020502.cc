// g++ 020502.cc -o 020502

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case1()
{
    date d1;
    date d2(2010, 1, 1);
    date d3(2000, Jan, 1);
    date d4(d2);
    cout << d1 << ", " << d2 << ", " << d3 << ", " << d4 << endl;
    cout << endl;

    assert(d1 == date(not_a_date_time));
    assert(d2 == d4);
    assert(d3 < d4);
}

void case2()
{
    date d1 = from_string("1999-12-31");
    date d2(from_string("2015/1/1"));
    date d3 = from_undelimited_string("20011118") ;

    cout << d1 << ", " << d2 << ", " << d3 << endl;
    cout << day_clock::local_day() << endl;
    cout << day_clock::universal_day() << endl;
    cout << endl;
}

void case3()
{
    date d1(neg_infin);
    date d2(pos_infin);
    date d3(not_a_date_time);
    date d4(max_date_time);
    date d5(min_date_time);

    cout << d1 << ", " << d2 << ", " << d3 << ", " << d4 << ", " << d5 << endl;

    try {
        // date d1(1399, 12,1);
        // date d2(10000, 1, 1);
        date d3(2017, 2, 29);
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }
}

int main() {
    case1();
    case2();
    case3();

    return 0;
}

