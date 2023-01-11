// g++ 070605.cc -o 070605

#include <iostream>
using namespace std;

#include <boost/assert.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/tuple/tuple_comparison.hpp>
using namespace boost;

typedef boost::tuple<int, double, string> my_tuple;

struct A {
};

bool operator ==(const struct A& a, const struct A& a2) {
    return true;
}

void case3()
{
    typedef boost::tuple<int, double, std::string> my_tuple;

    my_tuple t1 = boost::make_tuple(1, 100.0, std::string("abc"));
    my_tuple t2 = boost::make_tuple(1, 200.0, std::string("def"));
    assert(t1 < t2);

    my_tuple t3(t2);
    assert(t2 == t3);

    boost::tuple<A, int> ta1, ta2;
    assert(ta1 == ta2);
}

int main() {
    case3();

    return 0;
}

