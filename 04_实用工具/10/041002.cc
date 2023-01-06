// g++ 041002.cc -o 041002

#include <iostream>
#include <bitset>
using namespace std;

#include <boost/current_function.hpp>
using namespace boost;

double func()
{
    cout << BOOST_CURRENT_FUNCTION << endl;
    return 0.0;
}

string str = BOOST_CURRENT_FUNCTION;  // Wrong

void case2()
{
    cout << str << endl;
    cout << __FUNCTION__ << endl;
    cout << BOOST_CURRENT_FUNCTION << endl;

    func();
}

int main() {
    case2();

    return 0;
}

