// g++ 070205.cc -o 070205

#include <iostream>
using namespace std;

#include <boost/dynamic_bitset.hpp>
#include <boost/utility.hpp>
using namespace boost;

void case4()
{
    dynamic_bitset<> db(4, BOOST_BINARY(0101));

    assert(db.test(0) && !db.test(1));
    assert(db.any() && !db.none());
    assert(db.count() == 2);

    {
        dynamic_bitset<> db(4, BOOST_BINARY(0101));

        db.flip();
        assert(db.to_ulong() == BOOST_BINARY(1010));

        db.set();
        assert(!db.none());

        db.reset();
        assert(!db.any() );

        db.set(1, 1);
        assert(db.count() == 1);
    }

    {
        dynamic_bitset<> db(5, BOOST_BINARY(00101));

        auto pos = db.find_first();
        assert(pos == 0);

        pos = db.find_next(pos);
        assert(pos == 2);
    }
}

int main() {
    case4();

    return 0;
}

