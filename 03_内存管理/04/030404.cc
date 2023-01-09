// g++ 030404.cc -o 030404
// valgrind --leak-check=full ./030404

#include <iostream>

#include <boost/smart_ptr.hpp>
using namespace boost;

class node {
public:
    ~node() {
        std::cout << "deleted" << std::endl;
    }
    // typedef boost::shared_ptr<node> ptr_type;  // Memory leak
    typedef boost::weak_ptr<node> ptr_type;
    ptr_type next;
};

void case3()
{
    auto p1 = make_shared<node>();
    auto p2 = make_shared<node>();
    p1->next = p2;
    p2->next = p1;

    assert(p1.use_count() == 1);
    assert(p2.use_count() == 1);

    if (!p1->next.expired()) {
        auto p3 = p1->next.lock();
        std::cout << p3.use_count() << std::endl;
    }
}

int main() {
    case3();

    return 0;
}

