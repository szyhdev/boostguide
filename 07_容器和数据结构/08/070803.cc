// g++ 070803.cc -o 070803

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/variant.hpp>
using namespace boost;

typedef variant<int, double, string> var_t;

void case2()
{
    var_t v(1);
    v = 2.13;
    assert(v.type() == typeid(double));

    var_t v2("string type");
    cout << get<string>(v2) << endl;

    v2 = v;
    cout << get<int>(var_t(108)) << endl;
    cout << endl;
}

void case3()
{
    var_t v;
    assert(v.type() == typeid(int));
    assert(v.which() == 0);

    v = "variant demo";
    cout << *get<string>(&v) << endl;

    try
    {
        cout << get<double>(v) << endl;
    }
    catch (bad_get &)
    {
        cout << "bad_get" << endl;
    }
}

int main() {
    case2();
    case3();

    return 0;
}

