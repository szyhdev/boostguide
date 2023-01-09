// g++ 030803.cc -o 030803
// valgrind --leak-check=full ./030803

#include <iostream>
using namespace std;

#include <boost/pool/object_pool.hpp>
using namespace boost;

struct demo_class {
public:
    int a, b, c;
    demo_class(int x = 1, int y = 2, int z = 3) : a(x), b(y), c(z) {
    }
};

void case2()
{
    object_pool<demo_class> pl;

    auto p = pl.malloc();
    assert(pl.is_from(p));
    assert((p->a != 1) || (p->b != 2) || (p->c != 3));

    p = pl.construct(7, 8, 9);
    assert((p->a == 7) && (p->b == 8) && (p->c == 9));

    object_pool<string> pls;
    for (int i = 0; i < 5; ++i) {
        string* ps = pls.construct("hello object_pool");
        cout << *ps << endl;
    }
}

int main()
{
    case2();

    return 0;
}

