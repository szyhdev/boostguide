// g++ 020504.cc -o 020504

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case5()
{
    date d(2017, 1, 23);

    cout << to_simple_string(d) << endl;
    cout << to_iso_string(d) << endl;
    cout << to_iso_extended_string(d) << endl;
    cout << d << endl;

    cout << "input date: ";
    cin >> d;
    cout << d << endl;
}

int main() {
    case5();

    return 0;
}

