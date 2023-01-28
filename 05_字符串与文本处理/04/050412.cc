// g++ 050412.cc -o 050412

#include <iostream>
using namespace std;

#include <boost/algorithm/string.hpp>
using namespace boost;
    
typedef find_iterator<string::iterator> string_find_iterator;
typedef split_iterator<string::iterator> string_split_iterator;

void case11()
{
    string str("Samus||samus||mario||||Link");
    cout << str << endl << endl;

    string_find_iterator pos, end;
    for (pos = make_find_iterator(str, first_finder("samus", is_iequal()));
            pos != end; ++pos) {
        cout << "[" << *pos << "]";
    }
    cout << endl << endl;

    string_split_iterator p, endp;
    for (p = make_split_iterator(str, first_finder("||", is_equal()));
            p != endp; ++p) {
        cout << "[" << *p << "]";
    }
    cout << endl << endl;

    auto pos2 = make_find_iterator(str, first_finder("samus", is_iequal()));
    decltype(pos2) end2;
    for (; pos2 != end2; ++pos2) {
        cout << "[" << *pos2 << "]";
    }
    cout << endl;
}

int main()
{
    case11();

    return 0;
}

