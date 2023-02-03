// g++ 110106.cc -o 110106

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#include <boost/ref.hpp>
using namespace boost;

struct square {
    typedef void result_type;
    result_type operator ()(int& x)
    {
        x = x * x;
    }
};

void case7()
{
    typedef double (*pfunc)(double);
    pfunc pf = sqrt;
    cout << std::ref(pf)(5.0) << endl;

    square sq;
    int x = 5;
    std::ref(sq)(x);
    cout << x << endl;

    vector<int> v = { 1, 2, 3, 4, 5 };
    for_each(v.begin(), v.end(), std::ref(sq));

    for_each(v.begin(), v.end(), [] (const int& x) {
        cout << x << " ";
    });
    cout << endl;
}

int main() {
    case7();

    return 0;
}

