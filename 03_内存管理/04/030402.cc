// g++ 030402.cc -o 030402
// valgrind --leak-check=full ./030402

#include <iostream>

#include <boost/smart_ptr.hpp>
using namespace boost;

void case1()
{
    shared_ptr<int> sp(new int(10));
    assert(sp.use_count() == 1);
    std::cout << "*sp = " << *sp << std::endl;

    weak_ptr<int> wp(sp);
    assert(sp.use_count() == 1);
    assert(wp.use_count() == 1);
    assert(!wp.empty());
    if (!wp.expired())
    {
        shared_ptr<int> sp2 = wp.lock();
        *sp2 = 100;
        std::cout << "*sp = " << *sp << ", *sp2 = " << *sp2 << std::endl;
        assert(sp.use_count() == 2);
        assert(sp2.use_count() == 2);
        assert(wp.use_count() == 2);
    }
    assert(wp.use_count() == 1);

    sp.reset();
    assert(wp.expired());
    assert(!wp.lock());
    assert(wp.lock() == nullptr);
}

int main() {
    case1();

    return 0;
}

