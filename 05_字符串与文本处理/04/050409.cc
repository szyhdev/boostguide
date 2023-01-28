// g++ 050409.cc -o 050409

#include <iostream>
using namespace std;

#include <boost/algorithm/string.hpp>
using namespace boost;

void case8()
{
    string str = "Samus beat the monster.\n";
    cout << "str = " << str;
    replace_last(str, "beat", "kill");
    cout << "after replace_last: " << str;
    replace_tail(str, 9, "ridley.\n");
    cout << "after replace_tail: " << str;
    cout << "str = " << str;
    cout << endl;

    cout << "str = " << str;
    cout << "after ierase_all_copy of \"samus\": " <<
            ierase_all_copy(str, "samus");
    cout << "after replace_nth_copy of \"l\" with \"L\": " <<
            replace_nth_copy(str, "l", 2, "L");
    cout << "after erase_tail_copy of size of 8: " <<
            erase_tail_copy(str, 8) << endl;
    cout << "str = " << str;
}

int main()
{
    case8();

    return 0;
}

