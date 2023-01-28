// g++ 050302.cc -o 050302

#include <time.h>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#include <boost/utility/string_ref.hpp>
using namespace boost;

void case1()
{
    const char* cstr = "Days of Future Past";
    cout << "cstr = " << cstr << endl;
    string str(cstr);
    cout << "str = " << str << endl;
    
    string_ref sv1(cstr);
    cout << "sv1 = " << sv1 << endl;
    string_ref sv2(str);
    cout << "sv2 = " << sv2 << endl;
    assert((sv1 == sv2) && (sv1 == cstr) && (sv2 == str));
    string_ref sv3(cstr, 4);
    cout << "sv3 = " << sv3 << endl;
    assert(sv3 == str.substr(0, 4));
    string_ref sv4, sv5;
    sv4 = cstr;
    cout << "sv4 = " << sv4 << endl;
    sv5 = str;
    cout << "sv5 = " << sv5 << endl;
    assert(sv4 == sv5);
    cout << endl;
}

void case2()
{
    const char* cstr = "Apple iPhone iPad";
    cout << "cstr = " << cstr << endl;
    string_ref sv(cstr);
    assert(!sv.empty());
    assert(sv.size() == strlen(cstr));
    for (auto& x: sv) {
        cout << x;
    }
    cout << endl;

    assert(sv.front() == 'A');
    assert(sv[1] == 'p');
    assert(sv.find('i') == 6);
    auto substr = sv.substr(6, 6);
    assert(substr == "iPhone");
    string str = sv.to_string();
    assert(str == sv);
    sv.clear();
    assert(sv.empty());
}

void case3()
{
    const char* cstr = "Apple iPhone iPad";
    string_ref sv = cstr;
    sv.remove_prefix(6);
    assert(sv.starts_with("iP"));
    sv.remove_suffix(5);
    assert(sv.ends_with("one"));
    cout << endl;
}

void case4()
{
    auto trunk = [] (string_ref str) -> string_ref {
        return str.substr(0, 5);
    };
    cout << trunk("abcdefg") << endl;
    cout << endl;
}

void case5()
{
    string init = "123456";
    vector<string> v;
    for (int i = 0; i < 50000000; i++) {
        v.push_back(to_string(i) + "_" + init);
    }

    unsigned int c = 0;
    time_t start = time(0);
    for (int i = 0; i < 50000000; i++) {
       string res = v[i];
       string s = res.substr(0, 5);
       c += s.size();
    }
    cout << time(0) - start << endl;
    cout << c << endl;

    c = 0;
    start = time(0);
    for (int i = 0; i < 50000000; i++) {
       string_ref res = v[i];
       string_ref sv = res.substr(0, 5);
       c += sv.size();
    }
    cout << time(0) - start << endl;
    cout << c << endl;
}

int main()
{
    case1();
    case2();
    case3();
    case4();
    case5();

    return 0;
}

