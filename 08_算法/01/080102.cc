// g++ 080102.cc -o 080102

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/foreach.hpp>
using namespace boost;
using namespace boost::assign;

void case2() {
    vector<int> v = (list_of(1), 2, 3, 4, 5);
    BOOST_FOREACH(auto& x, v) {
        cout << x << " ";
    }
    cout << endl;
    BOOST_FOREACH(auto& x, v) {
        ++x;
    }
    BOOST_FOREACH(auto& x, v) {
        cout << x << " ";
    }
    cout << endl << endl;

    set<int> s = list_of(10)(20)(30);
    BOOST_FOREACH(auto& x, s) {
        cout << x << " ";
    }
    cout << endl;
    int x;
    BOOST_FOREACH(x, s) {
        if (++x % 7 == 0) {
            cout << x << endl;
        }
    }
    BOOST_FOREACH(auto& x, s) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    case2();

    return 0;
}

