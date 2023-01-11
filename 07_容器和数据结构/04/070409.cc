// g++ 070409.cc -o 070409

#include <iostream>
using namespace std;

#include <boost/bimap.hpp>
#include <boost/bimap/vector_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/unordered_multiset_of.hpp>
#include <boost/bimap/unconstrained_set_of.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::bimaps;
using namespace boost::assign;

template<typename T>
void print_map(T &m) {
    for (auto& x: m) {
        cout << x.first << ":" << x.second << endl;
    }
}

void case7()
{
    typedef bimap<int, string> bm_t;
    bm_t bm;
    bm.left.insert(bm_t::left_value_type(1, "one"));
    bm.right.insert(bm_t::right_value_type("two", 222));
    print_map(bm.right);
}

int main() {
    case7();

    return 0;
}

