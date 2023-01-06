// g++ 040705.cc -o 040705

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
using namespace boost;

struct my_err {
};

void case3()
{
    try
    {
        // throw enable_error_info(my_err()) << errinfo_errno(10);
        throw enable_error_info(std::runtime_error("runtime")) <<
                errinfo_at_line(__LINE__);
    }
    catch (boost::exception& e)
    {
        // cout << *get_error_info<errinfo_errno>(e) << endl;
        cout << *get_error_info<errinfo_at_line>(e) << endl;
    }
}

int main() {
    case3();

    return 0;
}

