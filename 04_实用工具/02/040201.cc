// g++ 040201.cc -o 040201

#include <boost/core/ignore_unused.hpp>
using namespace boost;

int func1(int x, int y) {
    int i = 0;
    ignore_unused(x, i);

    return y;
}

int main() {
    func1(1, 2);

    return 0;
}

