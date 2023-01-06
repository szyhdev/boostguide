// g++ 040502.cc -o 040502

#include <iostream>
#include <cassert>
using namespace std;

#include <boost/logic/tribool.hpp>
#include <boost/logic/tribool_io.hpp>
using namespace boost;

void case1()
{
    tribool tb(true);
    tribool tb2(!tb);

    if (tb) {
        cout << "true" << endl;
    }

    tb2 = indeterminate;
    assert(indeterminate(tb2));
    cout << "tb2 = " << tb2 << endl;

    if (tb2 == indeterminate) {
        cout << "never reach here" << endl;
    }

    if (indeterminate(tb2))
    {
        cout << "indeterminate" << endl;
    }

    cout << (tb2 || true) << endl;
    cout << (tb2 && false) << endl;
    cout << endl;
}

void case2()
{
    tribool tb(indeterminate);

    if (tb) {
        cout << "never reach here" << endl;
    }
    if (!tb) {
        cout << "never reach here" << endl;
    }

    if (indeterminate(tb)) {
        cout << "indeterminate" << endl;
    }
}

int main() {
    case1();
    case2();

    return 0;
}

