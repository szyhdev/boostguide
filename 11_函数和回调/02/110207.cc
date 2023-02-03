// g++ 110207.cc -o 110207

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

#include <boost/bind/bind.hpp>
#include <boost/rational.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;
using namespace boost::placeholders;

int f(int a, int b) {
    return a + b;
}

void case1()
{
    cout << bind(f, _1, _2)(10, 20) << endl;
    const arg<1>& arg1 = _1;
    const arg<2>& arg2 = _2;
    cout << bind(f, arg1, arg2)(10, 20) << endl;
    auto& _ax = _1;
    auto& _ay = _2;
    cout << bind(f, _ax, _ay)(10, 20) << endl;
    decltype(_1)& _dx = _1;
    decltype(_2)& _dy = _2;
    cout << bind(f, _dx, _dy)(10, 20) << endl;
    cout << endl;
}

void case2()
{
    auto gr = bind(greater<int>(), _1, _2);
    cout << gr(10, 20) << endl;
    cout << endl;
}

int g(int a, int b, int c) {
    return a + b * c;
}

struct func {
    int operator ()(int a, int b) {
        return a + b;
    }
};

void case3()
{
    int x = 10;
    cout << bind(g, _1, boost::cref(x), boost::ref(x))(10) << endl;
    func af;
    cout << bind<int>(boost::ref(af), _1, _2)(10, 20) << endl;

    auto r = boost::ref(x);
    {
        int* y = new int(20);
        r = boost::ref(*y);
        cout << r << endl;
        cout << bind(g, r, 1, 1)() << endl;
        delete y;
    }
    // cout << bind(g, r, 1, 1)() << endl;  // Runtime error
    cout << endl;
}

void case4()
{
    cout << bind(f, 10, bind(g, _1, 10, 10))(10) << endl;
    cout << endl;
}

typedef rational<int> ri;

void print_rational_vector(const vector<ri>& v) {
    for (auto e: v) {
        // cout << "(" << e.numerator() << ", " << e.denominator() << ")" << " ";
        cout << e << " ";
    }
    cout << endl;
}

void case5()
{
    vector<ri> v = { ri(1, 2), ri(3, 4), ri(5, 6) };
    print_rational_vector(v);

    auto numerator1 = remove_if(v.begin(), v.end(), bind(&ri::numerator, _1) == 1);
    v.erase(numerator1);
    assert(find_if(v.begin(), v.end(), bind(&ri::numerator, _1) == 1) == v.end());
    print_rational_vector(v);

    v.insert(v.begin(), ri(1, 2));
    print_rational_vector(v);
    auto pos = find_if(v.begin(), v.end(), (bind(&ri::numerator, _1) > 3) && (bind(&ri::denominator, _1) < 8));
    cout << *pos << endl;
    auto pos2 = find_if(v.begin(), v.end(), [] (ri& r) {
        return (r.numerator() > 3) && (r.denominator() < 8);
    });
    cout << *pos2 << endl;
    cout << endl;
}

int h(int a, int b) {
    cout << "h(int, int): ";
    return a + b;
}

double h(double a, double b) {
    cout << "h(double, double): ";
    return a + b;
}

typedef int (*h_type1)(int, int);
typedef double (*h_type2)(double, double);

void case6()
{
    // cout << bind(h, 1, 2)() << endl;  // Compile error
    h_type1 ph1 = h;
    h_type2 ph2 = h;
    cout << bind(ph1, 1, 2)() << endl;
    cout << bind(ph2, 1, 2)() << endl;

    // auto lc = bind(boost::contains, _1, "a");  // Compile error
    auto lc = [] (const string& x) {
        return contains(x, "d");
    };
    cout << lc("abcdefg") << endl;

    vector<string> vs = { "fox", "lion", "bear" };
    // auto pos = find_if(vs.begin(), vs.end(), bind(contains, _1, "n")); // Compile error
    auto pos = find_if(vs.begin(), vs.end(), [] (const string& s) {
        return contains(s, "n");
    });
    cout << *pos << endl;
    cout << endl;
}

void case7()
{
    bind<int>(printf, "%d + %d = %d\n", _1, 1, _2)(6, 7);
}

int main() {
    case1();
    case2();
    case3();
    case4();
    case5();
    case6();
    case7();

    return 0;
}

