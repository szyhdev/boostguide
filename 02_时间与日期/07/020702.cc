// g++ 020702.cc -o 020702

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

days operator ""_D(unsigned long long n)
{
    return days(n);
}

weeks operator ""_W(unsigned long long n)
{
    return weeks(n);
}

date operator ""_YMD(const char*  s, std::size_t)
{
    return from_string(s);
}

void case2()
{
    auto d = 100_D;
    auto w = 1_W;

    assert(d.days() == 100);
    assert(w.days() == (7_D).days());

    auto today = "2014/11/3"_YMD;
    cout << today << endl;
}

int main()
{
    case2();

    return 0;
}

