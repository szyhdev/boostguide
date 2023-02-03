// g++ 110102.cc -o 110102

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

#include <boost/ref.hpp>
using namespace boost;

void case2()
{
    int x = 10;
    boost::reference_wrapper<int> rw(x);
    assert(x == rw);
    (int&)rw = 100;
    assert(x == 100);

    boost::reference_wrapper<int> rw2(rw);
    assert(rw2.get() == 100);

    string str;
    boost::reference_wrapper<string> rws(str);
    *rws.get_pointer() = "test reference_wrapper";
    cout << rws.get().size() << endl;
}

int main() {
    case2();

    return 0;
}

