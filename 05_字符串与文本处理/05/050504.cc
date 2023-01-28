// g++ 050504.cc -o 050504

#include <iostream>
using namespace std;

#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost;
using namespace boost::xpressive;

void case1()
{
    cout << R"(regex = "a.c")" << endl;
    cregex reg1 = cregex::compile("a.c");
    assert(regex_match("abc", reg1));
    assert(regex_match("a+c", reg1));
    assert(!regex_match("ac", reg1));
    assert(!regex_match("abd", reg1));
    assert(!regex_match("abbc", reg1));
    cout << endl;
}

void case2()
{
    cout << R"---(regex = "\d{6}(1|2)\d{3}(0|1)\d[0-3]\d\d{3}(X|\d)")---" << endl;
    cregex reg2 = cregex::compile(R"---(\d{6}(1|2)\d{3}(0|1)\d[0-3]\d\d{3}(X|\d))---", icase);
    assert(regex_match("999555197001019999", reg2));
    assert(regex_match("99955519700101999X", reg2));
    assert(regex_match("99955520100101999x", reg2));
    assert(!regex_match("99955520100101999Z", reg2));
    assert(!regex_match("99955530100101999X", reg2));
    assert(!regex_match("999555201099019998", reg2));
    assert(!regex_match("999555201012419991", reg2));
    cout << endl;
}

void case3()
{
    cregex reg3 = cregex::compile(R"---(\d{6}((1|2)\d{3})((0|1)\d)([0-3]\d)(\d{3}(X|\d)))---", icase);
    cregex reg4 = cregex::compile("\\d{6}((1|2)\\d{3})((0|1)\\d)([0-3]\\d)(\\d{3}(X|\\d))", icase);
    cmatch what;
    if (regex_match("99955519700101999x", what, reg3)) {
        for (auto& x: what) {
            cout << "[" << x << "]";
        }
        cout << endl;
        cout << "date: " << what[1] << what[3] << what[5] << endl;
    }
    if (regex_match("99955519700101999x", what, reg4)) {
        for (auto& x: what) {
            cout << "[" << x << "]";
        }
        cout << endl;
        cout << "date: " << what[1] << what[3] << what[5] << endl;
    }
    cout << endl;
}

void case4()
{
    cout << R"("^re.*" and ".*txt$")" << endl;
    string str("readme.txt");
    sregex start_reg = sregex::compile("^re.*");
    sregex end_reg = sregex::compile(".*txt$");
    assert(regex_match(str, start_reg));
    assert(regex_match(str, end_reg));
}

int main()
{
    case1();
    case2();
    case3();
    case4();

    return 0;
}

