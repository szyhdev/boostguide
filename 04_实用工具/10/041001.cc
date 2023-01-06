// g++ 041001.cc -o 041001

#include <iostream>
#include <bitset>
using namespace std;

#include <boost/utility.hpp>
using namespace boost;

void case1()
{
    cout << hex << showbase;
    cout << BOOST_BINARY(0110) << endl;
    cout << BOOST_BINARY(0110 1101) << endl;
    cout << BOOST_BINARY(10110110 01) << endl;
    cout << bitset<5>(BOOST_BINARY(0110)) << endl;

    cout << BOOST_BINARY_UL(101 1001) << endl;
    long long x = BOOST_BINARY_LL(1101);
    cout << x << endl;
}

int main() {
    case1();

    return 0;
}

