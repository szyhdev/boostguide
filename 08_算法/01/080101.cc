// g++ 080101.cc -o 080101

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/foreach.hpp>
using namespace boost;
using namespace boost::assign;

void case1()
{
    vector<int> v = (list_of(1), 2, 3, 4, 5);
    BOOST_FOREACH(auto x, v) {
        cout << x << " ";
    }
    cout << endl << endl;

    string str("boost foreach");
    BOOST_FOREACH(auto& c, str) {
        cout << c;
    }
    cout << endl;
}

int main() {
    case1();

    return 0;
}

