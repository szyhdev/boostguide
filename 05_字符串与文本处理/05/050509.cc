// g++ 050509.cc -o 050509

#include <iostream>
using namespace std;

#include <boost/algorithm/string.hpp>
#include <boost/xpressive/xpressive_dynamic.hpp>
#include <boost/xpressive/xpressive_static.hpp>
using namespace boost;
using namespace boost::xpressive;

struct formater {
    string operator ()(const cmatch& m) const {
        return to_upper_copy(m[0].str());
    }
};

void case11()
{
    cregex_compiler rc;
    rc["reg1"] = rc.compile("a|b|c");
    rc["reg2"] = rc.compile("\\d*");
    assert(!regex_match("abc", rc["reg1"]));
    assert(regex_match("123", rc["reg2"]));
}

void case12()
{
    cregex_compiler rc;
    try {
        rc.compile("\\d{");
    }
    catch (...) {
        cout << "exception caught" << endl;
    }
    cout << endl;
}

void case13()
{
    char str1[] = "*Link*||+Mario+||Zelda!!!||Metroid";
    cout << str1 << endl;
    cregex reg1 = cregex::compile("\\w+", icase);
    cout << regex_replace(str1, reg1, formater()) << endl;
    cout << str1 << endl;
}

void case14()
{
    const char str2[] = "123abc";
    cregex reg2 = bos >> *_d >> + _w;
    assert(regex_match(str2, reg2));
}

int main()
{
    case11();
    case12();
    case13();
    case14();

    return 0;
}

