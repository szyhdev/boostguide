// g++ 070610.cc -o 070610

#include <iostream>
using namespace std;

#include <boost/assert.hpp>
#include <boost/assign.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace boost;
using namespace boost::assign;

struct demo {
    int x;
    double y;
    vector<string> str;
};

typedef boost::tuple<int, double, vector<string>> my_tuple;

typedef boost::tuple<int, string> my_tuple_1;
typedef boost::tuple<int, my_tuple_1> my_tuple_2;

typedef boost::tuple<int, double, string> my_tuple_3;

int main() {
    assert(sizeof(demo) == sizeof(my_tuple));

    assert(typeid(int) == typeid(tuples::element<0, my_tuple_1>::type));
    assert(typeid(string) == typeid(tuples::element<1, my_tuple_1>::type));
    cout << tuples::length<my_tuple_2>::value << endl;
    cout << endl;

    int a = 10;
    int b = 20;
    cout << a << ", " << b << endl;
    tie(a, b) = tie(b, a);
    cout << a << ", " << b << endl;
    a = 10;
    b = 20;
    tie(a, b) = boost::make_tuple(b, a);
    cout << a << ", " << b << endl;
    cout << endl;

    vector<my_tuple_3> v = boost::assign::tuple_list_of(1, 1.0, "abc")(2, 2.0, "def");
    assert(v.size() == 2);
    v += boost::make_tuple(3, 3.0, "ghi"), boost::make_tuple(4, 4.0, "jkl");
    assert(v.size() == 4);
    for (auto t: v) {
        cout << t << endl;
    }

    return 0;
}

