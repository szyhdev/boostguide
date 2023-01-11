// g++ 070502.cc -o 070502

#include <iostream>
using namespace std;

#include <boost/circular_buffer.hpp>
#include <boost/assign.hpp>
using namespace boost;

void case1()
{
    circular_buffer<int> cb(5);
    assert(cb.empty());

    cb.push_back(1);
    cb.push_front(2);
    assert(cb.front() == 2);
    cb.insert(cb.begin(), 3);
    for (auto pos = cb.begin(); pos != cb.end(); ++pos) {
        cout << *pos << " ";
    }
    cout << endl;

    cb.pop_front();
    assert(cb.size() == 2);
    cb.pop_back();
    assert(cb[0] = 2);
    for (auto pos = cb.begin(); pos != cb.end(); ++pos) {
        cout << *pos << " ";
    }
    cout << endl;

    circular_buffer<int> cb1 = (assign::list_of(1), 2, 3);
    circular_buffer<int> cb2 = (assign::list_of(3), 4, 5);
    circular_buffer<int> cb3 = cb1;

    assert(cb1 < cb2);
    assert(cb1 == cb3);
}

int main() {
    case1();

    return 0;
}

