// g++ 040707.cc -o 040707

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
#include <boost/throw_exception.hpp>
using namespace boost;

struct my_err {
};

void case4()
{
    try {
        throw enable_error_info(my_err()) << errinfo_errno(101) <<
                errinfo_api_function("fopen");
    }
    catch (boost::exception& e) {
        cout << diagnostic_information(e) << endl;
    }

    try {
        BOOST_THROW_EXCEPTION(std::logic_error("logic"));
    }
    catch (boost::exception& e) {
        cout << diagnostic_information(e);
    }
}

int main() {
    case4();

    return 0;
}

