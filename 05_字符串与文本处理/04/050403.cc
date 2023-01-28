// g++ 050403.cc -o 050403

#include <iostream>
using namespace std;

#include <boost/algorithm/string.hpp>
using namespace boost;

void case2()
{
    string str("FireEmblem Heroes\n");
    cout << "original = " << str;
    cout << endl;

    cout << "upper copy = " << to_upper_copy(str);
    cout << "original = " << str;
    cout << endl;

    to_lower(str);
    cout << "original after to_lower = " << str;
}

int main()
{
    case2();

    return 0;
}

