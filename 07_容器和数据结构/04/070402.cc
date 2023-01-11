// g++ 070402.cc -o 070402

#include <iostream>
using namespace std;

#include <boost/bimap.hpp>
using namespace boost;

void case1()
{
    bimap<int, string> bm;

    bm.left.insert(make_pair(1, "111"));
    bm.left.insert(make_pair(2, "222"));
    bm.right.insert(make_pair("string", 10));
    bm.right.insert(make_pair("bimap", 20));

    for (auto pos = bm.left.begin(); pos != bm.left.end(); ++pos) {
        cout << "left[" << pos->first << "] = " << pos->second << endl;
    }
    cout << endl;
    for (auto pos = bm.right.begin(); pos != bm.right.end(); ++pos) {
        cout << "right[" << pos->first << "] = " << pos->second << endl;
    }
    cout << endl;

    // bm.right.begin()->second = 234;  // Compile error

    bm.left.insert(make_pair(2, "333"));      // Invalid insert
    bm.right.insert(make_pair("string", 6));  // Invalid insert
    for (auto pos = bm.left.begin(); pos != bm.left.end(); ++pos) {
        cout << "left[" << pos->first << "] = " << pos->second << endl;
    }
    cout << endl;

    {
        bimap<int, string> bm;
        typedef decltype(bm)::value_type vt;
        typedef decltype(bm)::relation r;
        bm.insert(vt(3, "333"));
        bm.insert(r(4, "444"));
        for (auto pos = bm.left.begin(); pos != bm.left.end(); ++pos) {
            cout << "left[" << pos->first << "] = " << pos->second << endl;
        }
    }
}

int main() {
    case1();

    return 0;
}

