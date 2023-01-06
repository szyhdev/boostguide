// g++ 040303.cc -o 040303

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#include <boost/optional.hpp>
using namespace boost;

void case2()
{
    optional<int> op0;
    optional<int> op1(none);
    assert(!op0);
    assert(op0 == op1);

    assert(op1.value_or(253) == 253);
    cout << op1.value_or_eval([] () {
        return 874;
    }) << endl;

    optional<string> ops("test");
    assert(ops.value_or("xxx") == "test");
    cout << ops.value_or_eval([] () {
        return "xxx";
    }) << endl;
    cout << *ops << endl;
    ops.emplace("monado", 3);
    assert(*ops == "mon");

    vector<int> v(10);
    optional<vector<int>&> opv(v);
    assert(opv);
    opv->push_back(5);
    assert(opv->size() == 11);
    for (auto x: opv.value()) {
        cout << x << " ";
    }
    cout << endl << endl;

    opv = none;
    assert(!opv);
}

optional<double> calc(int x) {
    return optional<double>(x != 0, 1.0 / x);
}

optional<double> sqrt_op(double x) {
    return optional<double>(x > 0, sqrt(x));
}

void case3()
{
    optional<double> d = calc(10);
    if (d) {
        cout << *d << endl;
        cout << d.value() << endl;
    }

    d = sqrt_op(-10);
    if (!d) {
        cout << "no result"<< endl;
    }
}

int main() {
    case2();
    case3();

    return 0;
}

