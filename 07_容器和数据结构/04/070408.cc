// g++ 070408.cc -o 070408

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

void case6()
{
    typedef bimap<set_of<tagged<int,struct id>>, multiset_of<tagged<string, struct name>>> bm_t;

    bm_t bm = assign::list_of<bm_t::relation>(1, "mario")(2, "peach");
    insert(bm.by<id>())(3, "wario")(4, "luigi");
    insert(bm.by<name>())("yoshi", 5)("olima", 6);
    print_map(bm.left);
    cout << endl;

    auto right_pos = bm.by<name>().find("yoshi");
    auto left_pos  = bm.project<id>(right_pos);
    ++left_pos;
    cout << "left[" << left_pos->get<id>() << "] = " << left_pos->get<name>() << endl;
}

int main() {
    case6();

    return 0;
}

