// g++ 070405.cc -o 070405

#include <iostream>
using namespace std;

#include <boost/bimap.hpp>
#include <boost/bimap/vector_of.hpp>
#include <boost/bimap/list_of.hpp>
#include <boost/bimap/multiset_of.hpp>
#include <boost/bimap/unordered_set_of.hpp>
#include <boost/bimap/unordered_multiset_of.hpp>
#include <boost/bimap/unconstrained_set_of.hpp>
using namespace boost;
using namespace boost::bimaps;

bimap<tagged<int, struct id>, vector_of<string>> bm11;
bimap<multiset_of<tagged<int, struct id>>,
        unordered_set_of<tagged<string, struct name>>> bm12;

template<typename T>
void print_map(T &m) {
    for (auto& x: m) {
        cout << x.first << ":" << x.second << endl;
    }
}

void case3()
{
    bimap<tagged<int, struct id>, tagged<string, struct name>> bm;

    bm.by<id>().insert(make_pair(1, "samus"));
    bm.by<id>().insert(make_pair(2, "adam"));

    bm.by<name>().insert(make_pair("link", 10));
    bm.by<name>().insert(make_pair("zelda", 11));

    print_map(bm.by<name>());
}

int main() {
    case3();

    return 0;
}

