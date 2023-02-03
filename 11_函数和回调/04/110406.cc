// g++ 110406.cc -o 110406

#include <iostream>
using namespace std;

#include <boost/signals2.hpp>
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

template<int N>
bool operator ==(const slots<N>&, const slots<N>&)
{
    return true;
}

void case5()
{
    signal<int(int)> sig;
    assert(sig.empty());

    sig.connect(0, slots<10>());
    sig.connect(0, slots<20>());
    sig.connect(1, slots<30>());
    assert(sig.num_slots() == 3);
    sig(2);
    cout << endl;

    sig.disconnect(0);
    assert(sig.num_slots() == 1);
    sig(2);

    sig.disconnect(slots<30>());
    assert(sig.empty());
}

int main() {
    case5();

    return 0;
}

