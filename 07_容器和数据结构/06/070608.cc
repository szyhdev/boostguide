// g++ 070608.cc -o 070608

#include <iostream>
using namespace std;

#include <boost/assert.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace boost;

typedef boost::tuple<int, double, string> my_tuple;

template<typename Tuple>
void print_tuple(const Tuple& t) {
    cout << t.get_head() << " ";
    print_tuple(t.get_tail());
}

template<>
void print_tuple(const tuples::null_type& t) {
}

int main() {
    my_tuple t(1, 1.0, "string");
    print_tuple(t);
    cout << endl;

    return 0;
}

