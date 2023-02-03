// g++ 110403.cc -o 110403

#include <iostream>
using namespace std;

#include <boost/signals2.hpp>
using namespace boost::signals2;

void slots1()
{
    cout << "slot1 called" << endl;
}

void slots2()
{
    cout << "slot2 called" << endl;
}

template<int N>
struct slots
{
    void operator ()()
    {
        cout << "slot" << N <<" called" << endl;
    }
};

void case1()
{
    signal<void()> sig;

    sig.connect(&slots1);
    sig.connect(&slots2, at_front);

    sig();
    cout << endl;
}

void case2()
{
    signal<void()> sig;

    sig.connect(slots<1>(), at_back);
    sig.connect(slots<100>(), at_front);

    sig.connect(5, slots<51>(), at_back);
    sig.connect(5, slots<55>(), at_front);

    sig.connect(3, slots<30>(), at_front);
    sig.connect(3, slots<33>(), at_back);

    sig.connect(10, slots<10>());

    sig();
}

int main() {
    case1();
    case2();

    return 0;
}

