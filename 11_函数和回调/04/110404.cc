// g++ 110404.cc -o 110404

#include <iostream>
using namespace std;

#include <boost/signals2.hpp>
#include <boost/optional/optional_io.hpp>
using namespace boost::signals2;

template<int N>
struct slots
{
    int operator ()(int x)
    {
        cout << "slot" << N <<" called" << endl;
        return x * N;
    }
};

void case3()
{
    signal<int(int)> sig;

    sig.connect(slots<10>());
    sig.connect(slots<20>());
    sig.connect(slots<30>());

    cout << *sig(2) << endl;
}

int main() {
    case3();

    return 0;
}

