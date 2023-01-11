// g++ 070407.cc -o 070407

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
#include <boost/bimap/support/lambda.hpp>
using namespace boost;
using namespace boost::bimaps;
using namespace boost::assign;

template<typename T>
void print_map(T &m) {
    for (auto& x: m) {
        cout << x.first << ":" << x.second << endl;
    }
}

void case5()
{
    typedef bimap<int, string> bm_t;

    bm_t bm = assign::list_of<bm_t::relation>(1, "mario")(2, "peach");
    print_map(bm.left);
    auto pos = bm.left.find(1);
    cout << "left[" << pos->first << "] = " << pos->second << endl;
    auto pos2 = bm.right.find("peach");
    cout << "right[" << pos2->first << "] = " << pos2->second << endl;
    cout << endl;

    pos = bm.left.find(1);
    bm.left.replace_key(pos, 111);
    bm.left.replace_data(pos, "luigi");
    print_map(bm.left);
    cout << endl;

    pos = bm.left.find(2);
    bm.left.modify_key(pos, _key = 222);
    bm.left.modify_data(pos, _data = "marcos");
    print_map(bm.left);
}

int main() {
    case5();

    return 0;
}

