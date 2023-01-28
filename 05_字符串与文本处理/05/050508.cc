// g++ 050508.cc -o 050508

#include <iostream>
using namespace std;

#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost;
using namespace boost::xpressive;

void case10()
{
    char str[] = "*Link*||+Mario+||Zelda!!!||Metroid";
    cout << "str = " << str << endl;
    cout << endl;

    cout << "regex = \"\\w+\"" << endl;
    cregex reg1 = cregex::compile("\\w+", icase);
    cregex_token_iterator pos(str, str + strlen(str), reg1);
    for (; pos != cregex_token_iterator(); ++pos) {
        cout << "[" << *pos << "]";
    }
    cout << endl << endl;

    cout << "regex = \"||\"" << endl;
    cregex reg2 = cregex::compile("\\|\\|");
    pos = cregex_token_iterator(str, str + strlen(str), reg2, -1);
    for (; pos != cregex_token_iterator(); ++pos) {
        cout << "[" << *pos << "]";
    }
    cout << endl;
}

int main()
{
    case10();

    return 0;
}

