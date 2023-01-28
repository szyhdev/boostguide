// g++ 050103.cc -o 050103

#include <iostream>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;
using namespace boost::conversion;

template<typename T>
bool num_valid(const char* str) {
    T tmp;
    return try_lexical_convert(str, tmp);
}

void case2()
{
    try {
        int i = lexical_cast<int>("3.14");
        cout << "i = " << i << endl;
        int x = lexical_cast<int>("0x100");
        cout << "x = " << x << endl;
        long y = lexical_cast<long>("10000L");
        cout << "y = " << y << endl;
        double e = lexical_cast<double>("HelloWorld");
        cout << "e = " << e << endl;
        bool res = lexical_cast<bool>("false");
        cout << "res = " << res << endl;
    }
    catch (bad_lexical_cast& e) {
        cout << "exception caught: " << e.what() << endl;
    }
    cout << endl;

    int z;
    if (!try_lexical_convert("0x100", z)) {
        cout << "0x100 can't be converted to integer" << endl;
    }

    assert(num_valid<double>("3.14"));
    assert(!num_valid<int>("3.14"));
    assert(num_valid<int>("65535"));
}

int main()
{
    case2();

    return 0;
}

