// g++ 070302.cc -o 070302

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/unordered_set.hpp>
using namespace boost;
using namespace boost::assign;

typedef complex<double> complex_t;

void case1()
{
    unordered_set<int> s = { 1, 2, 3, 4, 5 };

    for (auto x: s) {
        cout << x << " ";
    }
    cout << endl;
    cout << s.size() << endl;

    s.clear();
    cout << s.empty() << endl;

    s.insert(8);
    s.insert(45);
    cout << s.size() << endl;
    cout << *s.find(8) << endl;

    s.erase(45);

    unordered_set<int> us1 = list_of(1)(2)(3);
    unordered_set<int> us2 = list_of(3)(2)(1);
    assert(us1 == us2 );
    cout << endl;
}

void case2()
{
    typedef complex<double> complex_t;
    unordered_set<complex_t> s;

    s.emplace(1.0, 2.0);
    s.emplace(3.0, 4.0);

    for (auto& x: s) {
        cout << x << " ";
    }
    cout << endl;

    s.emplace_hint(s.begin(), 5.0, 6.0);
    for (auto& x: s) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    case1();
    case2();

    return 0;
}

