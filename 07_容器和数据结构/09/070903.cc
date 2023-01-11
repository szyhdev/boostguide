// g++ 070903.cc -o 070903

#include <iostream>
using namespace std;

#include <boost/multi_array.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;

void case2()
{
    multi_array<int, 3> ma(extents[2][3][4]);
    assert(ma.shape()[0] == 2);

    std::array<std::size_t, 3> arr = { 4, 3, 2 };
    ma.reshape(arr);
    assert(ma.shape()[0] == 4);

    ma.resize(extents[2][9][9]);
    assert(ma.num_elements() == 2 * 9 * 9);
    assert(ma.shape()[1] == 9);
}

int main() {
    case2();

    return 0;
}

