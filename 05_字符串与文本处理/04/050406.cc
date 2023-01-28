// g++ 050406.cc -o 050406

#include <iostream>
using namespace std;

#include <boost/algorithm/string/classification.hpp>
using namespace boost;

struct is_zero_or_one {
    bool operator ()(char x) {
        return (x == '0') or (x == '1');
    }
};

auto is01 = [] (char x) {
    return (x == '0') or (x == '1');
};

void case5()
{
    cout << is_space()(' ') << endl;
    cout << is_space()('a') << endl;
    cout << is_from_range('a', 'z')('f') << endl;
    cout << is_from_range('a', 'z')('0') << endl;
    cout << endl;

    cout << is_zero_or_one()('1') << endl;
    cout << is_zero_or_one()('2') << endl;
    cout << is01('0') << endl;
    cout << is01('a') << endl;
}

int main()
{
    case5();

    return 0;
}

