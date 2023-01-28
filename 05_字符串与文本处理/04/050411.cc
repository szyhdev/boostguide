// g++ 050411.cc -o 050411

#include <iostream>
#include <vector>
using namespace std;

#include <boost/utility/string_ref.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;

void case10()
{
    vector<string> v = assign::list_of("Samus")("Link")("Zelda")("Mario");
    for (auto s: v) {
        cout << "[" << s << "] ";
    }
    cout << endl << endl;

    cout << join(v, "+") << endl;
    cout << endl;

    cout << join_if(v, "**", [] (string_ref s) {
        return contains(s, "a");
    });
    cout << endl;
}

int main()
{
    case10();

    return 0;
}

