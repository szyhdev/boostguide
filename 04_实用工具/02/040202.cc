// g++ 040202.cc -o 040202

#include <boost/core/ignore_unused.hpp>
using namespace boost;

int func2() {
    typedef int result_type;
    ignore_unused<result_type>();

    return 0;
}

int main() {
    func2();

    return 0;
}

