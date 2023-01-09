// g++ 030403.cc -o 030403
// valgrind --leak-check=full ./030403

#include <iostream>

#include <boost/smart_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
using namespace boost;

class self_shared : public enable_shared_from_this<self_shared>
{
public:
    self_shared(int n) : x(n) {
    }
    int x;
    void print() {
        std::cout << "self_shared: " << x << std::endl;
    }
};

void case2()
{
    auto sp = make_shared<self_shared>(313);
    sp->print();
    std::cout << sp.use_count() << std::endl;
    std::cout << std::endl;

    auto p = sp->shared_from_this();
    p->x = 1000;
    p->print();
    std::cout << p.use_count() << std::endl;
    std::cout << sp.use_count() << std::endl;
    std::cout << std::endl;
}

int main() {
    case2();

    self_shared ss(123);
    ss.print();
    // auto pss = ss.shared_from_this();  // Runtime error

    return 0;
}

