// g++ 070703.cc -o 070703

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/assign.hpp>
#include <boost/any.hpp>
using namespace boost;

void case2()
{
    any a(100);
    a = string("char*");
    a = vector<vector<int>>();

    a = "c str";
    cout << a.type().name() << endl;
    cout << any_cast<const char*>(&a) << endl;
    cout << any_cast<const char*>(a) << endl;

    string *ps = new string("abc");  // Not recommended
    a = ps;
    if (!a.empty() && any_cast<string*>(a)) {
        cout << *any_cast<string*>(a) << endl;
    }
    delete ps;
    
    boost::shared_ptr<string> ps2(new string("abc2"));
    any a2 = ps2;
    if (!a2.empty() && any_cast<boost::shared_ptr<string>>(a2)) {
        cout << *any_cast<boost::shared_ptr<string>>(a2) << endl;
    }
}

int main() {
    case2();

    return 0;
}

