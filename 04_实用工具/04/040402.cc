// g++ 040402.cc -o 040402

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
using namespace boost::assign;

void case1()
{
    vector<int> v;
    v += 1, 2, 3, 4, 5, 6 * 6;
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl << endl;

    set<string> s;
    s += "c", "cpp", "lua", "swift";
    for (auto x: s) {
        cout << x << " ";
    }
    cout << endl << endl;

    map<int, string> m;
    m += make_pair(1, "one"), make_pair(2, "two");
    for (auto x: m) {
        cout << "(" << x.first << " = " << x.second << ") ";
    }
    cout << endl;
}

int main() {
    case1();

    return 0;
}

