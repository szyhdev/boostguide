// g++ 050506.cc -o 050506

#include <iostream>
using namespace std;

#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost;
using namespace boost::xpressive;

void case7()
{
    string str("readme.txt");
    cout << "str = " << str << endl;
    cout << endl;
    sregex reg1 = sregex::compile("(.*)(me)");
    sregex reg2 = sregex::compile("(t)(.)(t)");

    cout << regex_replace(str, reg1, "manual") << endl;
    cout << regex_replace(str, reg1, "$1you") << endl;
    cout << regex_replace(str, reg1, "$&$&") << endl;
    cout << regex_replace(str, reg2, "$1N$3") << endl;
    cout << "str = " << str << endl;
    cout << endl;

    str = regex_replace(str, reg2, "$1$3");
    cout << "str = " << str << endl;
}

void case8()
{
    string str("2010 Happy new Year!!!");
    sregex reg1 = sregex::compile("^(\\d| )*");
    sregex reg2 = sregex::compile("!*$");

    cout << regex_replace(str, reg1, "") << endl;
    cout << regex_replace(str, reg2, "") << endl;
    str = regex_replace(str, reg1, "Y2000 ");
    cout << str << endl;
}

int main()
{
    case7();
    case8();

    return 0;
}

