// g++ 080302.cc -o 080302

#include <iostream>
#include <vector>
using namespace std;

#include <boost/assert.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/minmax_element.hpp>
using namespace boost;

void case2() {
    vector<int> v = { 3, 5, 2, 2, 10, 9, 10, 8 };
    BOOST_FOREACH(auto x, v) {
        cout << x << " ";
    }
    cout << endl;

    decltype(v.begin()) pos;
    
    pos = first_min_element(v.begin(), v.end());
    assert(pos - v.begin() == 2);
    cout << "first min: " << *pos << " at[" << pos - v.begin() << "]" << endl;
    
    pos = last_min_element(v.begin(), v.end());
    assert(pos - v.begin() == 3);
    cout << "last min: " << *pos << " at[" << pos - v.begin() << "]" << endl;
    
    auto x = first_min_last_max_element(v.begin(), v.end());
    assert((x.first - v.begin() == 2) && (x.second - v.begin() == 6));
    cout << "first min: " << *x.first << " at[" << x.first - v.begin() <<
            "], last max: " << *x.second << " at[" << x.second - v.begin() << "]" << endl;
}

int main() {
    case2();

    return 0;
}

