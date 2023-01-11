// g++ 070304.cc -o 070304

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/unordered_map.hpp>
using namespace boost;
using namespace boost::assign;

typedef complex<double> complex_t;
typedef boost::unordered_map<int, complex_t> um_t;

void case3()
{
    boost::unordered_map<int, string> um = map_list_of(1, "one")(2, "two")(3, "three");

    um.insert(make_pair(10, "ten"));
    cout << um[10] << endl;
    um[11] = "eleven";
    um[15] = "fifteen";

    auto p = um.begin();
    for (; p != um.end(); ++p) {
        cout << p->first << ":" << p->second << " ";
    }
    cout << endl;

    um.erase(11);
    cout << um.size() << endl;

    boost::unordered_map<int, string> um1 = map_list_of(1, "11")(2, "22");
    boost::unordered_map<int, string> um2 = map_list_of(1, "one")(2, "two");
    assert(um1 != um2);
}

void case4()
{
    um_t s;
    s.emplace(boost::unordered::piecewise_construct,
            make_tuple(1), make_tuple(1.0, 2.0));
    s.emplace(boost::unordered::piecewise_construct,
            make_tuple(3), make_tuple(3.0, 4.0));

    for (auto& x: s) {
        cout << x.first << ":" << x.second << " ";
    }
    cout << endl;

    s.emplace_hint(s.begin(), boost::unordered::piecewise_construct,
            make_tuple(5), make_tuple(5.0, 6.0));
    for(auto& x: s) {
        cout << x.first << ":" << x.second << " ";
    }
    cout << endl;
}

int main() {
    case3();
    case4();

    return 0;
}

