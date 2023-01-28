// g++ 050102.cc -o 050102

#include <iostream>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

void case1()
{
    int x = lexical_cast<int>("100");
    cout << "x = " << x << endl;
    long y = lexical_cast<long>("2000000000");
    cout << "y = " << y << endl;
    float pi = lexical_cast<float>("3.14159e4");
    cout << "pi = " << pi << endl;
    double e = lexical_cast<double>("2.71828");
    cout << "e = " << e << endl;
    double r = lexical_cast<double>("1.414,x", 5);
    cout << "r = " << r << endl;
    cout << endl;

    string str = lexical_cast<string>(456);
    cout << "str = " << str << endl;
    str = lexical_cast<string>(9999999999L);
    cout << "str = " << str << endl;
    str = lexical_cast<string>(0.618);
    cout << "str = " << str << endl;
    str = lexical_cast<string>(3.1415926535L);
    cout << "str = " << str << endl;
    str = lexical_cast<string>(0x10);
    cout << "str = " << str << endl;
    cout << endl;

    bool res = lexical_cast<bool>("1");
    // res = lexical_cast<bool>("false");  // Runtime error
    cout << "res = " << res << endl;
}

int main()
{
    case1();

    return 0;
}

