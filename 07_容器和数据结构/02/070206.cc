// g++ 070206.cc -o 070206

#include <iostream>
using namespace std;

#include <boost/dynamic_bitset.hpp>
#include <boost/utility.hpp>
using namespace boost;

void case5()
{
    cout << dec;

    dynamic_bitset<> db(10, BOOST_BINARY(1010101));
    cout << db.to_ulong() << endl;
    assert(db.to_ulong() == 85);

    db.append(10);
    cout << db << endl;
    cout << db.to_ulong() << endl;
    assert(db.to_ulong() == 10325);
    cout << endl;

    db.push_back(1);
    // BOOST_TEST_THROWS(db.to_ulong(), std::overflow_error);
    try
    {
        cout << db.to_ulong() << endl;
    }
    catch (std::overflow_error &)
    {
        cout << "can't convert to ulong."<< endl;
    }
    cout << endl;

    string str;
    to_string(db, str);
    cout << str << endl;

    dump_to_string(db , str);
    cout << str << endl;
}

int main() {
    case5();

    return 0;
}

