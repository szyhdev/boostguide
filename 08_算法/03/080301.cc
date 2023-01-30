// g++ 080301.cc -o 080301

#include <iostream>
#include <vector>
using namespace std;

#include <boost/foreach.hpp>
#include <boost/algorithm/minmax_element.hpp>
using namespace boost;

void case1() {
    vector<int> v = { 633, 90, 67, 83, 2, 100 };
    BOOST_FOREACH(auto x, v) {
        cout << x << " ";
    }
    cout << endl;

    auto x = boost::minmax_element(v.begin(), v.end());
    cout << "min: " << *x.first << endl;
    cout << "max: " << *x.second << endl;
}

int main() {
    case1();

    return 0;
}

