// g++ 050507.cc -o 050507

#include <iostream>
using namespace std;

#include <boost/xpressive/xpressive_dynamic.hpp>
using namespace boost;
using namespace boost::xpressive;

void case9()
{
    string str("Power-bomb, power-suit, pOWER-beam all items\n");
    cout << "str = " << str;

    sregex reg = sregex::compile("power-(\\w{4})", icase);
    sregex_iterator pos(str.begin(), str.end(), reg);
    sregex_iterator end;
    for (; pos != end; ++pos) {
        cout << "[" << (*pos)[0] << "]";
    }
    cout << endl;
}

int main()
{
    case9();

    return 0;
}

