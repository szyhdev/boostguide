// g++ 080103.cc -o 080103

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/foreach.hpp>
using namespace boost;
using namespace boost::assign;

#define foreach         BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

void case3() {
    int ar[] = {1, 2, 3, 4, 5};
    foreach(auto& x, ar) {
        cout << x << " ";
    }
    cout << endl << endl;

    map<int, string> m = {{1, "111"}, {2, "222"}, {3, "333"}};
    foreach(auto& x, m) {
        cout << x.first << " = " << x.second << endl;
    }
    cout << endl;

    vector<vector<int>> v = {{1, 2}, {3, 4}};
    foreach(auto& row, v) {
        reverse_foreach(auto& x, row) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() {
    case3();

    return 0;
}

