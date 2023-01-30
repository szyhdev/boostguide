// g++ 080105.cc -o 080105

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/foreach.hpp>
#include <boost/utility.hpp>
using namespace boost;
using namespace boost::assign;

typedef pair<int, string> pair_int_string;

void case5() {
    map<int, string> m;
    m += make_pair(1, "one"), make_pair(2, "two");
    // BOOST_FOREACH(pair<int, string> x, m) {  // Compile error
    BOOST_FOREACH(auto x, m) {
        cout << x.first << " = " << x.second << endl;
    }
    cout << endl;

    BOOST_FOREACH(pair_int_string x, m) {
        cout << x.first << " = " << x.second << endl;
    }
    cout << endl;

    BOOST_FOREACH(BOOST_IDENTITY_TYPE((pair<int, string>)) x, m) {
        cout << x.first << " = " << x.second << endl;
    }
}

int main() {
    case5();

    return 0;
}

