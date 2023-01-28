// g++ 050505.cc -o 050505

#include <iostream>
using namespace std;

#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost;
using namespace boost::xpressive;

void case5()
{
    char str1[] = "there is a POWER-suit item";
    cout << "str = " << str1 << endl;

    cout << R"---(regex = "(power)-(.{4})")---" << endl;
    cregex reg = cregex::compile("(power)-(.{4})", icase);
    assert(regex_search(str1, reg));
    cmatch what;
    regex_search(str1, what, reg);
    assert(what.size() == 3);
    cout << what[0] << " " << what[1] << " " << what[2] << endl;
    assert(!regex_search("error message", reg));
    cout << endl;
}

void case6()
{
    string str2("readme.TXT");
    cout << "str = " << str2 << endl;
    cout << R"(regex = "^re", "txt$" and "me")" << endl;
    sregex start_reg = sregex::compile("^re");
    sregex end_reg = sregex::compile("txt$", icase);
    assert(regex_search(str2, start_reg));
    assert(regex_search(str2, end_reg));
    assert(regex_search(str2, sregex::compile("me")));
}

int main()
{
    case5();
    case6();

    return 0;
}

