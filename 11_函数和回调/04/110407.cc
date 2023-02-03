// g++ 110407.cc -o 110407

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

void case6()
{
    signal<int(int)> sig;

    connection c1 = sig.connect(0, slots<10>());
    connection c2 = sig.connect(0, slots<20>());
    connection c3 = sig.connect(1, slots<30>());

    c1.disconnect();
    assert(sig.num_slots() == 2);
    assert(!c1.connected());
    assert(c2.connected());
    sig(2);
    cout << endl;

    sig.disconnect_all_slots();

    sig.connect(0, slots<10>());
    assert(sig.num_slots() == 1);
    sig(2);
    cout << endl;

    {
        scoped_connection sc = sig.connect(0, slots<20>());
        assert(sig.num_slots() == 2);
        sig(2);
        cout << endl;
    }

    assert(sig.num_slots() == 1);
    sig(2);
    cout << endl;
}

void case7()
{
    signal<int(int)> sig;

    connection c1 = sig.connect(0, slots<10>());
    connection c2 = sig.connect(0, slots<20>());
    assert(sig.num_slots() == 2);
    sig(2);
    cout << endl;

    cout << "blocking begin" << endl;
    {
        shared_connection_block block(c1);
        assert(sig.num_slots() == 2);
        assert(c1.blocked());
        sig(2);
    }
    cout << "blocking end" << endl;
    cout << endl;

    assert(!c1.blocked());
    sig(2);
}

int main() {
    case6();
    case7();

    return 0;
}

