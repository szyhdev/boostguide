// g++ 070103.cc -o 070103

#include <iostream>

#include <boost/array.hpp>
using namespace boost;

void case1()
{
    array<int, 10> ar;

    ar[0] = 1;
    ar.back() = 10;
    assert(ar[ar.max_size() - 1] == 10);

    ar.assign(777);
    for (auto x: ar) {
        std::cout << x << " ";
    }
    std::cout << std::endl << std::endl;

    int* p = ar.c_array();
    *(p + 5) = 253;
    std::cout << ar[5] << std::endl;
    std::cout << std::endl;

    ar.at(8) = 666;
    for (auto x: ar) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    std::sort(ar.begin(), ar.end());
    for (auto x: ar) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    case1();

    return 0;
}

