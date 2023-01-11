// g++ 070706.cc -o 070706

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/assign.hpp>
#include <boost/any.hpp>
using namespace boost;
using namespace boost::assign;

void case5()
{
    vector<any> v;
    v.push_back(10);
    v.push_back(1.414);
    v.push_back(boost::shared_ptr<int>(new int(100)));

    vector<any> v2 = list_of<any>(10)(0.618)(string("char"));
    cout << v2.size();
}

int main() {
    case5();

    return 0;
}

