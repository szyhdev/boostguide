// g++ 040901.cc -o 040901

#include <iostream>
using namespace std;

#include <boost/core/ignore_unused.hpp>
#include <boost/version.hpp>
#if BOOST_VERSION <= 106400
#include <boost/config/suffix.hpp>
#else
#include <boost/config/detail/suffix.hpp>
#endif
using namespace boost;

void case1()
{
    cout << BOOST_STRINGIZE(__LINE__) << endl;
    cout << std::boolalpha << (string("22") == BOOST_STRINGIZE(__LINE__)) << endl;

    int x = 255;
    cout << BOOST_STRINGIZE(x) << endl;

    ignore_unused(x);
}

int main() {
    case1();

    return 0;
}

