// g++ 040703.cc -o 040703

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
using namespace boost;

typedef error_info<struct tag_err_no, int> err_no;
typedef error_info<struct tag_err_str, string> err_str;

struct my_exception : virtual std::exception, virtual boost::exception {
};

void case1()
try {
    try {
        throw my_exception() << err_no(10);
    }
    catch (my_exception& e) {
        cout << *get_error_info<err_no>(e) << endl;
        cout << e.what() <<endl;
        e << err_str("other info");
        throw;
    }
}
catch (my_exception& e) {
    cout << *get_error_info<err_str>(e) << endl;
}

int main() {
    case1();

    return 0;
}

