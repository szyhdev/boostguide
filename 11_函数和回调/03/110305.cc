// g++ 110305.cc -o 110305

#include <iostream>
using namespace std;

#include <boost/bind/bind.hpp>
#include <boost/function.hpp>
using namespace boost;
using namespace boost::placeholders;

struct demo_class
{
    int add(int a, int b) {
        return a + b;
    }
    int operator ()(int x) const {
        return x * x;
    }
};

void case4()
{
    demo_class sc;
    boost::function<int(int)> func;

    func = boost::cref(sc);
    cout << func(10) << endl;
    cout << endl;
}

template<typename T>
struct summary
{
    typedef void result_type;
    T sum;

    summary(T v = T()) : sum(v) {
    }
    void operator ()(T const &x)
    {
        sum += x;
    }
};

void case5()
{
    vector<int> v = { 1, 3, 5, 7, 9 };
    summary<int> s;
    boost::function<void(int const&)> func(boost::ref(s));
    for_each(v.begin(), v.end(), func);
    cout << s.sum << endl;
}

int main() {
    case4();
    case5();

    return 0;
}

