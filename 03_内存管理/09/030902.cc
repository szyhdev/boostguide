// g++ 030902.cc -o 030902
// valgrind --leak-check=full ./030902

#include <iostream>
#include <vector>
using namespace std;

#include <boost/pool/singleton_pool.hpp>
#include <boost/pool/pool_alloc.hpp>
using namespace boost;

struct pool_tag {
};

typedef singleton_pool<pool_tag, sizeof(int)> spl;
typedef singleton_pool<struct pool_tag_2, sizeof(int)> spl2;

void case4()
{
    int* p = (int*)spl::malloc();
    assert(spl::is_from(p));
    // spl::release_memory();  // Memory leak
    spl::purge_memory();
}

int main()
{
    case4();

    return 0;
}

