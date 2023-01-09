// g++ 030804.cc -o 030804
// valgrind --leak-check=full ./030804

#include <iostream>
using namespace std;

#include <boost/pool/object_pool.hpp>
using namespace boost;

template<typename P, typename ... Args>
inline typename P::element_type* construct(P& p, Args&& ... args) {
    typename P::element_type* mem = p.malloc();
    assert(mem != 0);
    new (mem) typename P::element_type(std::forward<Args>(args) ...);
    return mem;
}

struct demo_class {
public:
    int a, b, c, d;
    demo_class(int w = 1, int x = 2, int y = 3, int z = 4) : a(w), b(x), c(y), d(z) {
        cout << "demo_class constructor" << endl;
    }
    ~demo_class() {
        cout << "demo_class destructor" << endl;
    }
};

void case3()
{
    object_pool<demo_class> pl;

    auto o = construct(pl, 7, 8, 9, 10);
    cout << o->a << " " << o->b << " " << o->c << " " << o->d << endl;
}

int main()
{
    case3();

    return 0;
}

