// g++ 040406.cc -o 040406

#include <iostream>
#include <cstdlib>
using namespace std;

#include <boost/assign.hpp>
using namespace boost::assign;

void case5() {
    vector<int> v = list_of(1).repeat(3, 2)(3)(4)(5);
    for (auto& x: v) {
        cout << x << " ";
    }
    cout << endl;

    multiset<int> ms;
    insert(ms).repeat_fun(5, &rand).repeat(2, 1), 10;
    for (auto& x: ms) {
        cout << x << " ";
    }
    cout << endl;

    deque<int> d;
    push_front(d).range(v.begin(), v.begin() + 5);
    for (auto& x: d) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    case5();

    return 0;
}

