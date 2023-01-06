// g++ 040504.cc -o 040504

#include <iostream>
#include <cassert>
using namespace std;

#include <boost/logic/tribool.hpp>
#include <boost/logic/tribool_io.hpp>
#include <boost/optional.hpp>
using namespace boost;

void case4()
{
    optional<bool> b;

    if (!b) {
        cout << "indeterminate" << endl;
    }

    b = false;
    if (b) {
        cout << "b = " << *b << endl;
    }

    if (!b) {
        cout << "false" << endl;
    }

    if (b && !*b) {
        cout << "real false" << endl;
    }
}

int main() {
    case4();

    return 0;
}

