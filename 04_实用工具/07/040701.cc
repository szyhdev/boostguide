// g++ 040701.cc -o 040701

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
using namespace boost;

class my_exception_test : public logic_error {
private:
    int err_no;
public:
    my_exception_test(const char* msg, int err) : logic_error(msg), err_no(err) {
    }
    int get_err_no() {
        return err_no;
    }
};

int main() {
    try {
        throw my_exception_test("error_msg", 123);
    }
    catch (my_exception_test& me) {
        cout << "error msg = " << me.what() << endl;
        cout << "error code = " << me.get_err_no() << endl;
    }

    return 0;
}

