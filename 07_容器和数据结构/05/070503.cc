// g++ 070503.cc -o 070503

#include <iostream>
using namespace std;

#include <boost/circular_buffer.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;

template<typename T>
void print(T& cb) {
    for (auto& x: cb) {
        cout << x << " ";
    }
    cout << endl;
}

void case2()
{
    circular_buffer<int> cb = (assign::list_of(1), 2, 3);
    print(cb);

    cb.push_back(4);
    print(cb);

    cb.push_back(5);
    print(cb);

    cb.pop_front();
    print(cb);
    cout << endl;
}

void case3()
{
    circular_buffer<int> cb =(assign::list_of(1), 2, 3, 4, 5);

    assert(cb.full());
    print(cb);

    int *p = cb.linearize();
    assert(p[0] == 1 && p[3] == 4);
    assert(cb.is_linearized());

    cb.rotate(cb.begin() + 2);
    print(cb);
}

int main() {
    case2();
    case3();

    return 0;
}

