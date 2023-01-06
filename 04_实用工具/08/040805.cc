// g++ 040805.cc -o 040805

#include <iostream>
using namespace std;

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
using namespace boost;
using namespace boost::uuids;

void case6()
{
    uuid u = string_generator()("01234567-89ab-cdef-0123-456789abcdef");
    string str = to_string(u);
    cout << str << endl;

    {
        uuid u = lexical_cast<uuid>("01234567-89ab-cdef-0123-456789abcdef");
        cout << u << endl;
        string str = lexical_cast<string>(u);
        cout << str << endl;
    }
}

int main() {
    case6();

    return 0;
}

