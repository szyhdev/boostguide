// g++ 030703.cc -o 030703
// valgrind --leak-check=full ./030703

#include <iostream>
using namespace std;

#include <boost/pool/pool.hpp>
using namespace boost;

void case1()
{
    pool<> pl(sizeof(int));

    int* p = static_cast<int*>(pl.malloc());
    if (p == nullptr) {
        cout << "malloc error: null pointer" << endl;
	return;
    }
    assert(pl.is_from(p));

    pl.free(p);
    for (int i = 0; i < 100; ++i)
    {
        pl.ordered_malloc(10);
    }
}

int main() {
    case1();

    return 0;
}

