// g++ 040704.cc -o 040704

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
using namespace boost;

struct my_exception : virtual std::exception, virtual boost::exception {
};

void case2()
try
{
    throw my_exception() << errinfo_api_function("call api") <<
            errinfo_errno(101);
}
catch (boost::exception& e)
{
    cout << *get_error_info<errinfo_api_function>(e) << endl;
    cout << *get_error_info<errinfo_errno>(e) << endl;
}

int main() {
    case2();

    return 0;
}

