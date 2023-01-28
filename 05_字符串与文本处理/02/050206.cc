// g++ 050206.cc -o 050206

#include <iostream>
#include <iomanip>
using namespace std;

#include <boost/format.hpp>
using namespace boost;

void case4()
{
    format fmt("%1% %2% %3% %2% %1% \n");
    cout << fmt % 1 % 2 % 3;
    fmt.bind_arg(2, 10);
    cout << fmt % 1 % 3;
    cout << endl;

    fmt.clear();
    cout << fmt % io::group(showbase, oct, 111) % 333;
    fmt.clear_binds();
    cout << endl;

    fmt.modify_item(1, io::group(hex, right, showbase, setw(8), setfill('*')));
    cout << fmt % 49 % 20 % 100;
}

int main()
{
    case4();

    return 0;
}

