// g++ 070609.cc -o 070609

#include <iostream>
using namespace std;

#include <boost/assert.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace boost;

typedef boost::tuple<int, double, string> my_tuple;

struct print_visitor {
    typedef void result_type;
    template<typename T>
    result_type operator ()(const T& t) {
        cout << t << " ";
    }
};

template<typename Visitor, typename Tuple>
typename Visitor::result_type visit_tuple(Visitor v, const Tuple& t) {
    v(t.get_head());
    return visit_tuple(v, t.get_tail());
}
 
template<>
void visit_tuple(print_visitor p, const tuples::null_type& t) {
}

template<typename T>
struct max_visitor {
    T* tmp;
    max_visitor(T* t) : tmp(t) {
    }

    typedef void result_type;
    result_type operator()(const T& t) {
        *tmp = *tmp < t ? t : *tmp;
    }
};

template<>
void visit_tuple(max_visitor<double> mv, const tuples::null_type& t) {
}

int main() {
    my_tuple t1(1, 1.0, "visitor");
    visit_tuple(print_visitor(), t1);
    cout << endl;

    boost::tuple<int, long, float, double> t2(100, 5, 3.14, 314.15);
    double* max_value = new double(t2.get_head());
    max_visitor<double> mv(max_value);
    visit_tuple(mv, t2);
    cout << *max_value << endl;

    return 0;
}

