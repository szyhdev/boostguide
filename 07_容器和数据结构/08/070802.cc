// g++ 070802.cc -o 070802

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/variant.hpp>
using namespace boost;

//////////////////////////////////////////
void case1()
{
    variant<int, float, string> v;
    v = "123";
    assert(v.type() == typeid(string));
    cout << v << endl;
}

int main() {
    case1();

    return 0;
}

