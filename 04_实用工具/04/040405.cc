// g++ 040405.cc -o 040405

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
using namespace boost::assign;

void case4() {
    vector<int> v = list_of(1)(2)(3)(4)(5);
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;

    deque<string> d = (list_of("power")("bomb"), "phazon", "suit");
    for (auto x: d) {
        cout << x << " ";
    }
    cout << endl;

    set<int> s = (list_of(10), 20, 30, 40, 50);
    for (auto x: s) {
        cout << x << " ";
    }
    cout << endl;

    map<int, string> m = list_of(make_pair(1, "one"))(make_pair(2, "two"));
    for (auto x: m) {
        cout << "(" << x.first << " = " << x.second << ") ";
    }
    cout << endl;

    map<int, int> m1 = map_list_of(1, 2)(3, 4)(5, 6);
    for (auto x: m1) {
        cout << "(" << x.first << " = " << x.second << ") ";
    }
    cout << endl;

    map<int, string> m2 = map_list_of(1, "one")(2, "two");
    for (auto x: m2) {
        cout << "(" << x.first << " = " << x.second << ") ";
    }
    cout << endl;
}

int main() {
    case4();

    return 0;
}

