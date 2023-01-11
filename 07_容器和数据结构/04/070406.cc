// g++ 070406.cc -o 070406

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

void case4()
{
    typedef bimap<multiset_of<int>, vector_of<string>> bm_t;

    bm_t bm = assign::list_of<bm_t::relation>(1, "111")(2, "222");
    assign::insert(bm.left)(3, "333")(4, "444");
    assign::push_back(bm.right)("555", 5)("666", 6);

    print_map(bm.left);
}

int main() {
    case4();

    return 0;
}

