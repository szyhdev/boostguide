// g++ 020703.cc -o 020703

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

void case1()
{
    date d(2014, 11, 3);
    date_facet* dfacet = new date_facet("%Y年%m月%d日");
    cout.imbue(locale(cout.getloc(), dfacet));
    cout << d << endl;

    time_facet* tfacet = new time_facet("%Y年%m月%d日%H点%M分%S%F秒");
    cout.imbue(locale(cout.getloc(), tfacet));
    cout << ptime(d, hours(21) + minutes(50) + millisec(100)) << endl;
}

int main()
{
    case1();

    return 0;
}

