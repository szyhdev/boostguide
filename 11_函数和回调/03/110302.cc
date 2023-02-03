// g++ 110302.cc -o 110302

#include <iostream>
using namespace std;

#include <boost/bind/bind.hpp>
#include <boost/function.hpp>
using namespace boost;

int func_no_argument() {
    cout << "no argument" << endl;

    return 0;
}

void case1()
{
    boost::function<int()> func, func1;
    boost::function<int(int, int, int)> func2;

    assert(func.empty());
    assert(!func);

    boost::function0<int> func0;
    func0 = func_no_argument;
    assert(func0);
    func0();
    func0.clear();
    assert(!func0);
}

int main() {
    case1();

    return 0;
}

