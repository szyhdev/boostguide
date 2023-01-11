// g++ 070607.cc -o 070607

#include <iostream>
using namespace std;

#include <boost/assert.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace boost;

typedef boost::tuple<int, double, string> my_tuple;

my_tuple func() {
    return boost::make_tuple(1, 1.0, "string");
}

void case5()
{
    int i;
    double d;
    string s;
    tie(i, d, s) = func();
    cout << i << ", " << d << ", " << s << endl;

    tie(i, s) = std::make_pair(100, "abc");
    cout << i << ", " << s << endl;

    tie(tuples::ignore, d, tuples::ignore) = func();
    cout << d << endl;
}

int main() {
    case5();

    return 0;
}

