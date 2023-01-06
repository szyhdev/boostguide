// g++ 040803.cc -o 040803

#include <iostream>
using namespace std;

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace boost::uuids;

void case3()
{
    uuid u = nil_generator()();
    assert(u.is_nil());
    u = nil_uuid();
    assert(u.is_nil());

    string_generator sgen;
    uuid u1 = sgen("0123456789abcdef0123456789abcdef");
    cout << u1 << endl;
    uuid u2 = sgen("01234567-89ab-cdef-0123-456789abcdef");
    cout << u2 << endl;
    uuid u3 = sgen(L"{01234567-89ab-cdef-0123-456789abcdef}");
    cout << u3 << endl;
    cout << endl;
}

void case4()
{
    uuid www_xxx_com = string_generator()("{0123456789abcdef0123456789abcdef}");
    name_generator ngen(www_xxx_com);
    uuid u1 = ngen("mario");
    cout << u1 << endl;
    assert(!u1.is_nil() && u1.version() == uuid::version_name_based_sha1);
    uuid u2 = ngen("link");
    cout << u2 << endl;

    random_generator rgen;
    uuid u = rgen();
    assert(u.version() == uuid::version_random_number_based);
    cout << u << endl;
}

int main() {
    case3();
    case4();

    return 0;
}

