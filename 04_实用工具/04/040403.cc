// g++ 040403.cc -o 040403

#include <iostream>
#include <forward_list>
using namespace std;

#include <boost/assign.hpp>
using namespace boost::assign;

void case2() {
    vector<int> v;
    push_back(v)(1)(2)(3)(4)(5);
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;

    list<string> l;
    push_front(l)("c")("cpp")("lua")("swift");
    for (auto x: l) {
        cout << x << " ";
    }
    cout << endl;

    forward_list<string> fl;
    push_front(fl)("matrix")("reload");
    for (auto x: fl) {
        cout << x << " ";
    }
    cout << endl;

    set<double> s;
    insert(s)(3.14)(0.618)(1.732);
    for (auto x: s) {
        cout << x << " ";
    }
    cout << endl;

    map<int, string> m;
    insert(m)(1, "one")(2, "two");
    for (auto x: m) {
        cout << "(" << x.first << " = " << x.second << ") ";
    }
    cout << endl << endl;
}

void case3() {
    vector<int> v2;
    push_back(v2), 1, 2, 3, 4, 5;
    push_back(v2)(6), 7, 64 / 8, (9), 10;
    for (auto x: v2) {
        cout << x << " ";
    }
    cout << endl;

    deque<string> d;
    push_front(d)() = "breath", "of", "the", "wild";
    assert(d.size() == 5);
    for (auto& x : d) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    case2();
    case3();

    return 0;
}

