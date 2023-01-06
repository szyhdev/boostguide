// g++ 040802.cc -o 040802

#include <iostream>
using namespace std;

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace boost::uuids;

void case1() {
    uuid u;
    assert(uuid::static_size() == 16);
    assert(u.size() == 16);

    vector<unsigned char> v(16, 7);
    std::copy(v.begin(), v.end(), u.begin());
    assert(u.data[0] == u.data[1] && u.data[15] == 7);
    cout << u << endl;

    fill_n(u.data + 10, 6, 8);
    cout << u << endl;
    cout << endl;
}

void case2()
{
    uuid u;
    std::fill_n(u.begin(), u.size(), 0xab);
    assert(!u.is_nil());
    assert(u.variant() == u.variant_rfc_4122);
    assert(u.version() == u.version_unknown);
    cout << u << endl;

    memset(u.data, 0, 16);
    assert(u.is_nil());

    uuid u1, u2;
    std::fill_n(u1.begin(), u1.size(), 0xab);
    std::fill_n(u2.begin(), u2.size(), 0x10);
    cout << u1 << endl;
    cout << u2 << endl;
    assert(u1 != u2 && u1 > u2);

    u2.data[0] = 0xff;
    cout << u2 << endl;
    assert(u1 < u2);

    memset(u1.data, 0, 16);
    memset(u2.data, 0, 16);
    cout << u1 << endl;
    cout << u2 << endl;
    assert(u1 == u2);
}

int main() {
    case1();
    case2();

    return 0;
}

