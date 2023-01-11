// g++ 070702.cc -o 070702

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/assign.hpp>
#include <boost/any.hpp>
using namespace boost;

void case1()
{
    any a(10);

    int n = any_cast<int>(a);
    assert(n == 10);

    any_cast<int&>(a) = 20;
    assert(any_cast<int>(a) == 20);;

    try
    {
        any a;
        any_cast<int>(a);
    }
    catch (boost::exception&)
    {
        cout << current_exception_diagnostic_information();
    }

    any a1, a2(2.0);
    assert(any_cast<int*>(&a1) == nullptr);
    assert(any_cast<string*>(&a2) == nullptr);
}

int main() {
    case1();

    return 0;
}

