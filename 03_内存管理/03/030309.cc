// g++ 030309.cc -o 030309
// valgrind --leak-check=full ./030309

#include <iostream>
#include <exception>
#include <set>

#include <boost/smart_ptr.hpp>
#include <boost/smart_ptr/owner_less.hpp>
using namespace boost;

bool case4()
{
    auto p = make_shared<int>(776);
    assert(p);
    if (p) {
        std::cout << "implicit cast" << std::endl;
        std::cout << std::endl;
    }

    // return p;  // Compile error
    return static_cast<bool>(p);
}

void shared_pointer_cast_test()
{
    shared_ptr<std::exception> sp1(new std::bad_exception);

    auto sp2 = dynamic_pointer_cast<std::bad_exception>(sp1);
    auto sp3 = static_pointer_cast<std::exception>(sp2);
    assert(sp1 == sp3);

    std::cout << "sp1 = " << sp1 << std::endl;
    std::cout << "sp2 = " << sp2 << std::endl;
    std::cout << "sp3 = " << sp3 << std::endl;
    std::cout << std::endl;
}

void any_func(void* p)
{
    std::cout << "some operation when exiting from scope" << std::endl;
}

void case5()
{
    shared_ptr<void> p(nullptr, any_func);
}

void case6()
{
    auto p1 = make_shared<std::pair<int, int>>(0, 1);
    shared_ptr<int> p2(p1, &p1->second);
    assert(p1.use_count() == 2 && p1.use_count() == p2.use_count());
    assert((void*)p1.get() != (void*)p2.get());
    assert(&p1->second == p2.get());

    std::cout << "(" << p1->first << ", " << p1->second << ")" << std::endl;
    std::cout << *p2 << std::endl;
    *p2 = 10;
    std::cout << "(" << p1->first << ", " << p1->second << ")" << std::endl;
    std::cout << *p2 << std::endl;
    std::cout << std::endl;
}

void case7() {
    typedef shared_ptr<int> int_ptr;
    typedef owner_less<int_ptr> int_ptr_less;

    int_ptr p1(new int(10));
    int n = 20;
    int_ptr p2(p1, &n);
    assert(!int_ptr_less()(p1, p2) && !int_ptr_less()(p2, p1));
    std::cout << p1.use_count() << std::endl;
    std::cout << p2.use_count() << std::endl;

    typedef std::set<int_ptr> int_ptr_set;
    int_ptr_set s;
    s.insert(p1);
    s.insert(p2);
    std::cout << s.size() << std::endl;
}

int main() {
    case4();
    shared_pointer_cast_test();
    case5();
    case6();
    case7();

    return 0;
}

