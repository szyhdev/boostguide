// g++ 070305.cc -o 070305

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
using namespace boost;
using namespace boost::assign;

void case5()
{
    unordered_set<int> us = (list_of(1), 2, 3, 4);
    cout << us.bucket_count() << endl;

    for (size_t i = 0; i < us.bucket_count(); ++i) {
        cout << us.bucket_size(i) << " ";
    }
    cout << endl;

    cout << us.max_load_factor();
    cout << endl;
}

struct demo_class {
    int a;
    demo_class(int value) : a(value) {
    }
    friend bool operator ==(const demo_class& l, const demo_class& r) {
        return l.a == r.a;
    }
};

size_t hash_value(const demo_class& s) {
    return boost::hash<int>()(s.a);
}

int main() {
    case5();
    cout << endl;

    unordered_set<demo_class, size_t(*)(const demo_class&)> us(0, hash_value);
    us.emplace(345);
    us.emplace(678);
    us.emplace(123);
    for (auto dc: us) {
        cout << dc.a << " ";
    }
    cout << endl;

    return 0;
}

