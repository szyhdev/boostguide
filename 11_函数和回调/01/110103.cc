// g++ 110103.cc -o 110103

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#include <boost/ref.hpp>
using namespace boost;

void case3()
{
    double x = 2.71828;
    auto rw = boost::cref(x);
    cout << typeid(rw).name() << endl;

    string str;
    auto rws = boost::ref(str);
    cout << typeid(rws).name() << endl;

    cout << sqrt(boost::ref(x)) << endl;
}

int main() {
    case3();

    return 0;
}

