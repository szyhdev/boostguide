// g++ 040606.cc -o 040606

#include <iostream>
#include <cassert>
using namespace std;

#include <boost/operators.hpp>
using namespace boost;

template<typename T>
class my_smart_ptr : public dereferenceable<my_smart_ptr<T>, T*>
{
    T* p;
public:
    my_smart_ptr(T* x) : p(x) {
    }
    ~my_smart_ptr() {
        delete p;
    }
    T& operator *() const {
        return *p;
    }
};

void case5()
{
    my_smart_ptr<string> p(new string("123"));
    assert(p->size() == 3);
}

int main() {
    case5();

    return 0;
}

