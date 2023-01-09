// g++ 030204.cc -o 030204
// valgrind --leak-check=full ./030204

#include <iostream>
#include <memory>
using namespace std;

#include <boost/smart_ptr.hpp>
#include <boost/smart_ptr/make_unique.hpp>
using namespace boost;

struct posix_file {
    posix_file() {
        cout << "open file" << endl;
    }
    ~posix_file() {
        cout << "close file" << endl;
    }
};

void case_unique()
{
    // int* up(new int);  // Memory leak
    unique_ptr<int> up(new int);
    assert(up);
    *up = 10;
    cout << *up << endl;
    up.reset();
    assert(!up);
    cout << endl;

    auto p = boost::make_unique<int>(10);
    assert(p);
    cout << *p << endl;
    bool equal = typeid(up).hash_code() == typeid(p).hash_code();
    cout << "type of up " << (equal ? "=" : "!=") << " type of p" << endl;
    cout << endl;
}

int main() {
    case_unique();

    unique_ptr<posix_file[]> uppf(new posix_file[5]);

    return 0;
}

