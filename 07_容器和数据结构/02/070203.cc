// g++ 070203.cc -o 070203

#include <iostream>
using namespace std;

#include <boost/dynamic_bitset.hpp>
#include <boost/utility.hpp>
using namespace boost;

void case2()
{
    dynamic_bitset<> db;
    db.resize(10, true);
    cout << db << endl;
    db.resize(5);
    cout << db << endl << endl;

    {
        dynamic_bitset<> db(5, BOOST_BINARY(01110));
        cout << db << endl;
        assert(db.size() == 5);
        db.clear();
        assert(db.empty() && db.size()==0);
    }

    assert(dynamic_bitset<>(64).num_blocks() == 1);
    assert(dynamic_bitset<>(65).num_blocks() == 2);

    {
        dynamic_bitset<> db(5, BOOST_BINARY(01001));
        db.push_back(true);
        assert(db.to_ulong() == BOOST_BINARY_UL(101001));
    }

    {
        dynamic_bitset<> db(5, BOOST_BINARY(01001));
        db.append(BOOST_BINARY(101));
        assert(db.size() == sizeof(unsigned long) * 8 + 5);
	string db_str;
	to_string(db, db_str);
        cout << db << " (len = " << db_str.size() << ")" << endl;
    }
}

int main() {
    case2();

    return 0;
}

