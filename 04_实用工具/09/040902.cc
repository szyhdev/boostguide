// g++ 040902.cc -o 040902

#include <iostream>
using namespace std;

#include <boost/version.hpp>
#if BOOST_VERSION <= 106400
#include <boost/config/suffix.hpp>
#else
#include <boost/config/detail/suffix.hpp>
#endif
using namespace boost;

struct static_int
{
    BOOST_STATIC_CONSTANT(int, v1 = 10);
    BOOST_STATIC_CONSTANT(int, v2 = 20);
};

int main() {
    cout << static_int::v1 << endl;
    cout << static_int::v2 << endl;

    return 0;
}

