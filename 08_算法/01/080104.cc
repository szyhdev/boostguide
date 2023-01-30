// g++ 080104.cc -o 080104

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/foreach.hpp>
#include <boost/array.hpp>
#include <boost/unordered_set.hpp>
#include <boost/circular_buffer.hpp>
using namespace boost;
using namespace boost::assign;

#define foreach         BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

void case4() {
    boost::array<int, 5> ar = (list_of(1), 2, 3, 4, 5);
    foreach(int x, ar) {
        cout << x << " ";
    }
    cout << endl << endl;

    pair<decltype(ar.begin()), decltype(ar.end())> range(ar.begin(), ar.end() - 2);
    foreach(auto x, range) {
        cout << x << " ";
    }
    cout << endl << endl;

    circular_buffer<int> cb = list_of(1)(2)(3);
    foreach(auto x, cb) {
        cout << x << " ";
    }
    cout << endl << endl;

    unordered_set<double> us = list_of(2.717)(3.14)(0.618);
    foreach(auto x, us) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    case4();

    return 0;
}

