// g++ 050204.cc -o 050204

#include <iostream>
using namespace std;

#include <boost/format.hpp>
using namespace boost;

void case2()
{
    string fmt_str1 = "%05d[\t]%-8.3f[\t]% 10s[\t]%05X\n";
    string fmt_str2 = R"(%05d[\t]%-8.3f[\t]% 10s[\t]%05X\n)";
    cout << "fmt_str1 = " << fmt_str1;
    cout << "fmt_str2 = " << fmt_str2;
    cout << endl << endl;

    format fmt1(fmt_str1);
    cout << "fmt1   = " << "fmt % 62 % 2.236 % \"123456789\" % 48" << endl;
    cout << "result = " << fmt1 % 62 % 2.236 % "123456789" % 48;
    cout << endl;

    format fmt2("%|05d|[\t]%|-8.3f|[\t]%| 10s|[\t]%|05X|\n");
    string str2 = R"(%|05d|[\t]%|-8.3f|[\t]%| 10s|[\t]%|05X|\n)";
    cout << "str2 = " << str2;
    cout << endl;
    cout << "fmt2   = " << "fmt % 62 % 2.236 % \"123456789\" % 48" << endl;
    cout << "result = " << fmt2 % 62 % 2.236 % "123456789" % 48;
}

int main()
{
    case2();

    return 0;
}

