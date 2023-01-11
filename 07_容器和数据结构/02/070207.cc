// g++ 070207.cc -o 070207

#include <iostream>
using namespace std;

#include <boost/dynamic_bitset.hpp>
#include <boost/utility.hpp>
using namespace boost;

void case6()
{
    dynamic_bitset<> db1(5, BOOST_BINARY(10101));
    dynamic_bitset<> db2(5, BOOST_BINARY(10010));

    cout << (db1 | db2) << endl;
    cout << (db1 & db2) << endl;
    cout << (db1 - db2) << endl;

    dynamic_bitset<> db3(5, BOOST_BINARY(101));
    assert(db3.is_proper_subset_of(db1));

    dynamic_bitset<> db4(db2);
    assert(db4.is_subset_of(db2));
    assert(!db4.is_proper_subset_of(db2));
}

int main() {
    case6();

    return 0;
}

