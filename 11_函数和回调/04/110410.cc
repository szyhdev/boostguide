// g++ 110410.cc -o 110410

#include <iostream>
using namespace std;

#include <boost/signals2.hpp>
#include <boost/random.hpp>
#include <boost/bind/bind.hpp>
using namespace boost;
using namespace boost::signals2;
using namespace boost::placeholders;

class demo_class
{
public:
    typedef signal<void()> signal_t;

    boost::shared_ptr<signal_t> sig;
    int x;
    demo_class() : sig(new signal_t), x(10) {
    }
};

void print()
{
    cout << "hello sig." << endl;
}

void case2()
{
    demo_class obj;
    assert(obj.sig.use_count() == 1);
    demo_class obj2(obj);
    assert(obj.sig.use_count() == 2);

    obj.sig->connect(&print);
    (*obj2.sig)();
    cout << endl;
}

template <int N>
struct my_slot {
    int operator ()(int x) {
        cout << "my_slot" << N << " called" << endl;
        return x * N;
    }
};

class my_combiner
{
public:
    typedef bool result_type;
    template<typename InputIterator> 
    result_type operator ()(InputIterator begin, InputIterator end) const {
        while (begin != end) {
            if (*begin > 100) {
                cout << "exit from my_combiner: " << *begin << endl;
                return true;
            }
	    ++begin;
        }
        return false;
    }
};

void case2_5()
{
    signal<int(int), my_combiner> sig;
    sig.connect(my_slot<10>());
    sig.connect(my_slot<20>());
    sig.connect(my_slot<30>());

    sig(6);
    cout << endl;
}

template<int N>
struct slots
{
    int operator ()(const connection& conn, int x) {
        cout << "conn = " << conn.connected() << endl;
        return x * N;
    }
};

void case3()
{
    typedef signal<int(int)> signal_t;
    typedef signal_t::extended_slot_type slot_t;
    signal_t sig;

    sig.connect_extended(slot_t(&slots<10>::operator(), slots<10>(), _1, _2));
    sig.connect_extended(slot_t(&slots<20>::operator(), slots<20>(), _1, _2));
    sig(5);
    cout << endl;
}

void f()
{
    cout << "func called" << endl;
}

void case4()
{
    boost::function<void()> func;
    func = f;
    func();

    signal<void()> sig;
    sig.connect(&f);
    sig();
    cout << endl;
}

template<typename Signature>
class sig_ex
{
public:
    typedef signal<Signature> signal_type;
    typedef typename signal_type::slot_type slot_type;

    connection connect(const slot_type& s) {
        return sig.connect(s);
    }

    connection operator +=(const slot_type& s) {
        return connect(s);
    }

    template<typename ... Args>
    typename signal_type::result_type operator ()(Args&& ... args) {
        return sig(std::forward<Args>(args) ...);
    }

private:
    signal_type sig;
};

template<int N>
struct slots_ex
{
    int operator ()(int x) {
        cout << "slot" << N << " called" << endl;
        return x * N;
    }
};

void case5()
{
    sig_ex<int(int)> sig;
    sig += slots_ex<10>();
    sig += slots_ex<5>();
    sig(2);
}

int main() {
    case2();
    case2_5();
    case3();
    case4();
    case5();

    return 0;
}

