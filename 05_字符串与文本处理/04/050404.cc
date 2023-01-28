// g++ 050404.cc -o 050404

#include <iostream>
using namespace std;

#include <boost/algorithm/string.hpp>
using namespace boost;

bool compare_incasesensitive(char ch1, char ch2) {
    return (ch1 == ch2) ||
            ((ch1 >= 'a') && (ch1 <= 'z') && (ch2 >= 'A') && (ch2 <= 'Z') && (ch2 + 32 == ch1)) ||
            ((ch1 >= 'A') && (ch1 <= 'Z') && (ch2 >= 'a') && (ch2 <= 'z') && (ch1 + 32 == ch2));
}

void case3()
{
    string str1("Power Bomb");
    assert(iends_with(str1, "bomb"));
    assert(!ends_with(str1, "bomb"));
    assert(starts_with(str1, "Pow"));
    assert(contains(str1, "er"));

    string str2 = to_lower_copy(str1);
    assert(iequals(str1, str2));

    string str3("power suit");
    assert(ilexicographical_compare(str1, str3));
    assert(all(str2.substr(0, 5), is_lower()));

    assert(starts_with(str1, "pow", compare_incasesensitive));
}

int main() {
    case3();

    return 0;
}

