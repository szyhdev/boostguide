// g++ 040304.cc -o 040304

#include <iostream>
using namespace std;

#include <boost/optional.hpp>
using namespace boost;

void case4()
{
    auto x = make_optional(5);
    assert(*x == 5);

    auto y = make_optional<double>(*x > 10, 1.0);
    assert(!y);
}

int main() {
    case4();

    return 0;
}

