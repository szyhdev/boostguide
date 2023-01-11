// g++ 070504.cc -o 070504

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

void case4()
{
    circular_buffer_space_optimized<int> cb(10);
    push_back(cb)(1), 2, 3, 4;
    print(cb);

    assert(cb.size() == 4);
    assert(cb.capacity() == 10);

    cb.resize(20, 5);
    assert(cb.size() == cb.capacity());
    print(cb);
}

int main() {
    case4();

    return 0;
}

