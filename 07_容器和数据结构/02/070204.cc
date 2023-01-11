// g++ 070204.cc -o 070204

#include <iostream>
using namespace std;

#include <boost/dynamic_bitset.hpp>
#include <boost/utility.hpp>
using namespace boost;

void case3()
{
    dynamic_bitset<> db1(4, BOOST_BINARY(1010));

    db1[0] &= 1;
    db1[1] ^= 1;
    cout << db1 << endl;

    dynamic_bitset<> db2(4, BOOST_BINARY(0101));
    assert(db1 > db2);

    cout << (db1 ^ db2) << endl;
    cout << (db1 | db2) << endl;
}

int main() {
    case3();

    return 0;
}

