// g++ 110408.cc -o 110408

#include <iostream>
using namespace std;

#include <boost/bind/bind.hpp>
#include <boost/signals2.hpp>
#include <boost/smart_ptr.hpp>
using namespace boost::signals2;
using namespace boost::placeholders;

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

void case8()
{
    typedef signal<int(int)> signal_t;
    signal_t sig;

    sig.connect(slots<10>());
    // boost::shared_ptr<slots<20>> p(new slots<20>);
    auto p = boost::make_shared<slots<20>>();

    sig.connect(signal_t::slot_type(ref(*p)).track(p));
    p.reset();
    assert(sig.num_slots() == 1);
    sig(1);
}

void case9()
{
    typedef signal<int(int)> signal_t;
    typedef signal_t::slot_type slot_t;
    signal_t sig;

    auto p1 = boost::make_shared<slots<10>>();
    auto p2 = boost::make_shared<slots<20>>();

    function<int(int)> func = ref(*p1);
    sig.connect(slot_t(func).track(p1));
    sig.connect(slot_t(&slots<20>::operator (), p2.get(), _1).track(p2));

    p1.reset();
    p2.reset();
    assert(sig.num_slots() == 0);
    sig(1);
}

int main() {
    case8();
    case9();

    return 0;
}

