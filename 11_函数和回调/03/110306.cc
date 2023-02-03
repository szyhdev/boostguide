// g++ 110306.cc -o 110306

#include <iostream>
using namespace std;

#include <boost/bind/bind.hpp>
#include <boost/function.hpp>
using namespace boost;
using namespace boost::placeholders;

class demo_class
{
private:
    typedef boost::function<void(int)> func_t;
    func_t func;
    int n;

public:
    demo_class(int i) : n(i) {
    }

    template<typename CallBack>
    void accept(CallBack f) {
        func = f;
    }

    void run()
    {
        func(n);
    }
};

void call_back_func(int i)
{
    cout << "call_back_func: " << i * 2 << endl;
}

void case1()
{
    demo_class dc(10);
    dc.accept(call_back_func);
    dc.run();
    cout << endl;
}

class call_back_obj
{
private:
    int x;

public:
    call_back_obj(int i) : x(i) {
    }

    void operator ()(int i)
    {
        cout << "call_back_obj: " << i * x++ << endl;
    }
};

void case2()
{
    demo_class dc(10);
    call_back_obj cbo(2);
    dc.accept(boost::ref(cbo));
    dc.run();
    dc.run();
    cout << endl;
}

class call_back_factory
{
public:
    void call_back_func1(int i)
    {
        cout << "call_back_factory1: " << i * 2 << endl;
    }
    void call_back_func2(int i, int j)
    {
        cout << "call_back_factory2: " << i * j * 2 << endl;
    }
};

void case3()
{
    demo_class dc(10);
    call_back_factory cbf;

    dc.accept(bind(&call_back_factory::call_back_func1, cbf, _1));
    dc.run();
    dc.accept(bind(&call_back_factory::call_back_func2, cbf, _1, 5));
    dc.run();
}

int main() {
    case1();
    case2();
    case3();

    return 0;
}

