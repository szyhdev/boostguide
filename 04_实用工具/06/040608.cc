// g++ 040608.cc -o 040608

#include <iostream>
#include <cassert>
using namespace std;

#include <boost/operators.hpp>
#include <boost/core/explicit_operator_bool.hpp>
using namespace boost;

struct demo_a_unsafe
{
    operator bool() const {
        return true;
    }
};

struct demo_b_unsafe
{
    operator bool() const {
        return false;
    }
};

struct demo_a
{
    BOOST_EXPLICIT_OPERATOR_BOOL()
    bool operator !() const {
        return false;
    }
    //explicit operator bool() const {
    //    return true;
    //}
};

struct demo_b
{
    BOOST_EXPLICIT_OPERATOR_BOOL_NOEXCEPT()
    bool operator !() const {
        return true;
    }
    //explicit operator bool() const {
    //    return false;
    //}
};

void case7()
{
    demo_a_unsafe au;
    demo_b_unsafe bu;
    assert(au != bu);
    assert(au > bu);

    demo_a a;
    demo_b b;
    assert(a && !b);
    // assert(a != b);  // Compile error
    // assert(a > b);  // Compile error
}

int main() {
    case7();

    return 0;
}

