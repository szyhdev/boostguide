// g++ 030303.cc -o 030303
// valgrind --leak-check=full ./030303

#include <iostream>
#include <memory>

#include <boost/smart_ptr.hpp>
using namespace boost;

void case3()
{
    shared_ptr<int> sp(new int(10));
    assert(sp.unique());

    shared_ptr<int> sp2 = sp;
    assert(sp == sp2 && sp.use_count() == 2);
    *sp2 = 100;
    assert(*sp == 100);

    sp.reset();
    assert(!sp);
}

class shared
{
private:
    shared_ptr<int> _p;
public:
    shared(shared_ptr<int> p) : _p(p) {
    }
    void print() {
        std::cout << "count = " << _p.use_count() <<
                ", value = " << *_p << std::endl;
    }
};

void print_func(shared_ptr<int> p)
{
    std::cout << "count = " << p.use_count() <<
            ", value = " << *p << std::endl;
}

void case4()
{
    shared_ptr<int> p(new int(100));
    shared s1(p), s2(p);
    s1.print();
    s2.print();

    *p = 20;
    print_func(p);

    s1.print();
}

int main() {
    case3();
    case4();

    return 0;
}

