// g++ 070404.cc -o 070404

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

bimap<int, unordered_set_of<string>> bm1;
bimap<multiset_of<int>, multiset_of<string>> bm2;
bimap<unordered_set_of<int>, list_of<string>> bm3;
bimap<vector_of<int>, unconstrained_set_of<string>> bm4;

template<typename T>
void print_map(T &m) {
    for (auto& x: m) {
        cout << x.first << ":" << x.second << endl;
    }
}

void case2()
{
    bimap<unordered_multiset_of<int>, unordered_multiset_of<string>> bm;

    bm.left.insert(make_pair(1, "111"));
    bm.left.insert(make_pair(2, "222"));
    bm.left.insert(make_pair(2, "555"));

    bm.right.insert(make_pair("string", 10));
    bm.right.insert(make_pair("bimap", 20));
    bm.right.insert(make_pair("bimap", 2));
    bm.right.insert(make_pair("555", 2));

    print_map(bm.left);
    cout << endl;

    {
        bimap<set_of<int>, vector_of<string> > bm;
        bm.left.insert(make_pair(1, "111"));
        bm.left[2] = "222";
        bm.left[300] = "bimap";
        bm.right.push_back(make_pair("bimap", 300));
        bm.right.push_back(make_pair("bimap", 200));
        // bm.right.insert(make_pair("string", 10));  // Compile error

        print_map(bm.left);
    }
}

int main() {
    case2();

    return 0;
}

