// g++ 070906.cc -o 070906

#include <iostream>
using namespace std;

#include <boost/multi_array.hpp>
#include <boost/assign.hpp>
using namespace boost;

void case6()
{
    typedef multi_array<int, 3> ma_type;
    typedef ma_type::extent_range range;
    ma_type ma(extents[range(1, 5)][4][range(-2, 2)]);
    ma[1][0][-2] = 10;

    ma.reindex(1);
    assert(ma[1][1][1] == 10);
    ma.reindex(std::array<int,3> { 1, 0, -4 });
    assert(ma[1][0][-4] == 10);

    cout << *ma.index_bases() << endl;
}

void case7()
{
    using namespace boost::detail::multi_array;

    typedef multi_array<int, 3> ma_type;
    typedef ma_type::index_range range;
    ma_type ma(extents[9][8][7]);

    auto view = ma[indices[range() < 3L][2L <= range() <= 5L][range()]];
    cout << *view.shape() << endl;
}

int main() {
    case6();
    case7();

    return 0;
}

