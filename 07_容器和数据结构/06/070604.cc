// g++ 070604.cc -o 070604

#include <iostream>
using namespace std;

#include <boost/assert.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace boost;

void case2()
{
    auto t = boost::make_tuple(1, "char[]", 100.0);
    std::cout << t << std::endl;

    assert(t.get<0>() == 1);
    assert(t.get<2>() == 100.0);

    std::cout << t.get<1>() << std::endl;
    std::cout << ++t.get<0>() << std::endl;
    std::cout << t << std::endl;

    get<0>(t);
    get<1>(t);
}

int main() {
    case2();

    return 0;
}

