// g++ 070805.cc -o 070805

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/variant.hpp>
#include <boost/mpl/vector.hpp>
using namespace boost;

template<BOOST_VARIANT_ENUM_PARAMS(typename T)>
void op_var(variant<BOOST_VARIANT_ENUM_PARAMS(T)>& v)
{
    cout << v << endl;
}

int main() {
    variant<int, double, string> v("string type");
    op_var(v);

    return 0;
}

