// g++ 110304.cc -o 110304

#include <iostream>
using namespace std;

#include <boost/bind/bind.hpp>
#include <boost/function.hpp>
using namespace boost;
using namespace boost::placeholders;

int f(int a, int b)
{
    return a + b;
}

void case2()
{
    boost::function<int(int, int)> func0;
    boost::function<decltype(f)> func;
    assert(!func);
    // cout << (func0 == func) << endl;  // Compile error

    func = f;
    assert(func);
    assert(func == f);
    assert(func.contains(&f));
    if (func) {
        cout << func(10, 20) << endl;
    }

    func = 0;
    assert(func.empty());
    cout << endl;
}

struct demo_class
{
    int add(int a, int b) {
        return a + b;
    }
    int operator ()(int x) const {
        return x * x;
    }
};

void case3()
{
    boost::function<int(demo_class&, int, int)> func1;
    func1 = bind(&demo_class::add, _1, _2, _3);
    demo_class sc;
    cout << func1(sc, 10, 20) << endl;

    boost::function<int(int, int)> func2;
    func2 = bind(&demo_class::add, &sc, _1, _2);
    cout << func2(10, 20) << endl;
}

int main() {
    case2();
    case3();

    return 0;
}

