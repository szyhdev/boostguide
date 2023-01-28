// g++ 050410.cc -o 050410

#include <iostream>
using namespace std;

#include <boost/algorithm/string.hpp>
using namespace boost;

void case9()
{
    string str = "Samus,Link.Zelda:::Mario-Luigi+zelda";
    cout << str << endl << endl;

    deque<string> d;
    ifind_all(d, str, "zELDA");
    assert(d.size() == 2);
    for (auto x: d) {
        cout << "[" << x << "] ";
    }
    cout << endl << endl;

    list<iterator_range<string::iterator>> l;
    split(l, str, is_any_of(",.:-+"));
    for (auto x: l) {
        cout << "[" << x << "] ";
    }
    cout << endl << endl;

    l.clear();
    split(l, str, is_any_of(".:-"), token_compress_on);
    for (auto x: l) {
        cout << "[" << x << "] ";
    }
    cout << endl;
}

int main()
{
    case9();

    return 0;
}

