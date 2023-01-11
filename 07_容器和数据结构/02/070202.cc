// g++ 070202.cc -o 070202

#include <iostream>
using namespace std;

#include <boost/dynamic_bitset.hpp>
#include <boost/utility.hpp>
using namespace boost;

void case1()
{
    dynamic_bitset<> db1;
    dynamic_bitset<> db2(10);
    dynamic_bitset<> db3(0x16, BOOST_BINARY(10101));
    dynamic_bitset<> db4(string("0100"));
    dynamic_bitset<> db5(db3);

    dynamic_bitset<> db6;
    db6 = db4;

    cout << "0x" << hex << db5.to_ulong() << endl;
    cout << db4[0] << db4[1] << db4[2] << endl;
}

int main() {
    case1();

    return 0;
}

