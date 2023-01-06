// g++ 040503.cc -o 040503

#include <iostream>
#include <cassert>
using namespace std;

#include <boost/logic/tribool.hpp>
#include <boost/logic/tribool_io.hpp>
using namespace boost;

BOOST_TRIBOOL_THIRD_STATE(unknown)

namespace tmp_ns
{
    BOOST_TRIBOOL_THIRD_STATE(unknown)
};

void case3()
{
    tribool tb(tmp_ns::unknown);
    assert(unknown(tb));
    assert(unknown(tb || false));
}

int main() {
    case3();

    return 0;
}

