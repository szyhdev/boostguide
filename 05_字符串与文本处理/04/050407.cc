// g++ 050407.cc -o 050407

#include <iostream>
using namespace std;

#include <boost/format.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;

void case6()
{
    format fmt("|%s|\n");
    string str1 = "  samus aran   ";
    cout << "original: " << fmt % str1;
    cout << fmt % trim_copy(str1);
    cout << "after trim_copy: " << fmt % str1;
    cout << fmt % trim_left_copy(str1);
    cout << "after trim_left_copy: " << fmt % str1;
    trim_right(str1);
    cout << "after trim_right: " << fmt % str1;
    cout << endl;

    string str2 = "2020 Happy new Year!!!";
    cout << fmt % trim_left_copy_if(str2, is_digit());
    cout << fmt % trim_right_copy_if(str2, is_punct());
    cout << fmt % trim_copy_if(str2, is_punct() || is_digit() || is_space());
}

int main()
{
    case6();

    return 0;
}

