// g++ 050408.cc -o 050408

#include <iostream>
using namespace std;

#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;

void case7()
{
    format fmt("value = %s, pos = %d\n");
    string str = "Long long ago, there was a king.";
    cout << "str = " << str << endl;
    iterator_range<string::iterator> range;

    range = find_first(str, "long");
    cout << "first of \"long\": " << fmt % range % (range.begin() - str.begin());
    range = ifind_first(str, "long");
    cout << "first case-insensitive of \"long\": " << fmt % range % (range.begin() - str.begin());
    range = find_nth(str, "ng", 2);
    cout << "2nd of \"ng\": " << fmt % range % (range.begin() - str.begin());
    range = find_head(str, 4);
    cout << "head 4 of str: " << fmt % range % (range.begin() - str.begin());
    range = find_tail(str, 5);
    cout << "tail 5 of str: " << fmt % range % (range.begin() - str.begin());
    range = find_first(str, "samus");
    assert(range.empty() && !range);
}

int main()
{
    case7();

    return 0;
}

