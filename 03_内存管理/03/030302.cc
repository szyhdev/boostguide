// g++ 030302.cc -o 030302
// valgrind --leak-check=full ./030302

#include <iostream>
#include <map>
#include <exception>

#include <boost/smart_ptr.hpp>
using namespace boost;

void case1()
{
    shared_ptr<int> spi(new int);
    assert(spi);
    *spi = 253;
    std::cout << spi << ", " << *spi << std::endl;

    shared_ptr<std::string> sps(new std::string("smart"));
    assert(sps->size() == 5);
    std::cout << sps << ", " << *sps << std::endl;

    // shared_ptr<int> dont_do_this(new int[10]);
    std::cout << std::endl;
}

void case2()
{
    typedef shared_ptr<std::string> sp_t;
    std::map<sp_t, int> m;
    sp_t sp(new std::string("one"));
    m[sp] = 111;
    for (auto x: m) {
        std::cout << "(" << *x.first << " = " << x.second << ")" << std::endl;
    }

    shared_ptr<std::exception> sp1(new std::bad_exception());
    auto sp2 = dynamic_pointer_cast<std::bad_exception>(sp1);
    auto sp3 = static_pointer_cast<std::exception>(sp2);
    assert(sp3 == sp2);
    assert(sp3 == sp1);
    std::cout << sp1.use_count() << std::endl;
}

int main() {
    case1();
    case2();

    return 0;
}

