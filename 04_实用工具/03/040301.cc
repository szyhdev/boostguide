// g++ 040301.cc -o 040301

#include <iostream>
using namespace std;

#include <boost/optional.hpp>
using namespace boost;

void case1()
{
    cout << typeid(none).name() << endl;
    cout << is_member_object_pointer<none_t>::value << endl;
}

int main() {
    case1();

    return 0;
}

