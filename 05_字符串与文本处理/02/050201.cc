// g++ 050201.cc -o 050201

#include <iostream>
using namespace std;

#include <boost/format.hpp>
using namespace boost;

void case1()
{
    cout << format("%s: %d + %d = %d\n") % "sum" % 1 % 2 % (1 + 2);

    format fmt("(%1% + %2%) * %2% = %3%\n");
    fmt % 2 % 5;
    fmt % ((2 + 5) * 5);
    cout << fmt.str();

    printf("(%d + %d) * %d = %d\n", 2, 5, 5, (2 + 5) * 5);
}

int main()
{
    case1();

    return 0;
}

