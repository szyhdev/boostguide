// g++ 050401.cc -o 050401

#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

#include <boost/algorithm/string.hpp>
using namespace boost;

void case1()
{
    string str("readme.txt");
    if (ends_with(str, "txt")) {
        cout << to_upper_copy(str) + " (UPPER)" << endl;
        assert(ends_with(str, "txt"));
        cout << str << endl;
    }
    cout << endl;

    replace_first(str, "readme", "followme");
    cout << str << endl;
    cout << endl;

    vector<char> v1(str.begin(), str.end());
    vector<char> v2 = to_upper_copy(erase_first_copy(v1, "txt"));
    for (auto ch: v2) {
        cout << ch;
    }
    cout << endl;
}

int main()
{
    case1(); 

    return 0;
}

