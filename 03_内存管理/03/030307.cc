// g++ 030307.cc -o 030307
// valgrind --leak-check=full ./030307

#include <iostream>

#include <boost/smart_ptr.hpp>
#include <boost/core/ignore_unused.hpp>
using namespace boost;

class abstract
{
public:
    virtual void f() = 0;
    virtual void g() = 0;
protected:
    virtual ~abstract() = default;
};

class impl : public abstract
{
public:
    impl() = default;
    virtual ~impl() = default;
public:
    virtual void f() {
        std::cout << "class impl: f()" << std::endl;
    }
    virtual void g() {
        std::cout << "class impl: g()" << std::endl;
    }
};

shared_ptr<abstract> create() {
    return make_shared<impl>();
}

void case2()
{
    auto p = create();
    p->f();
    p->g();

    abstract *q = p.get();
    ignore_unused(q);
    // delete q;

    std::cout << typeid(p).name() << std::endl;
    std::cout << typeid(shared_ptr<impl>).name() << std::endl;
}

int main() {
    case2();

    return 0;
}

