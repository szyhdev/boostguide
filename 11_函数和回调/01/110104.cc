// g++ 110104.cc -o 110104

#include <iostream>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

#include <boost/ref.hpp>
using namespace boost;

void case4()
{
    vector<int> v(10, 2) ;
    auto rw = boost::cref(v);
    assert(is_reference_wrapper<decltype(rw)>::value);
    assert(!is_reference_wrapper<decltype(v)>::value);

    string str;
    auto rws = boost::ref(str);
    cout << typeid(unwrap_reference<decltype(rws)>::type).name() << endl;
    cout << typeid(unwrap_reference<decltype(str)>::type).name() << endl;
    cout << endl;
}

void case5()
{
    set<int> s;
    auto rw = boost::ref(s);
    unwrap_ref(rw).insert(12);

    string str("test");
    auto rws = boost::cref(str);
    cout << unwrap_ref(rws) << endl;
    cout << unwrap_ref(str) << endl;
}

int main() {
    case4();
    case5();

    return 0;
}

