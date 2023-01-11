// g++ 070704.cc -o 070704

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/assign.hpp>
#include <boost/any.hpp>
using namespace boost;

template<typename T>
bool can_cast(any& a)
{
    return typeid(T) == a.type();
}

template<typename T>
T& get(any& a)
{
    assert(can_cast<T>(a));
    return *any_cast<T>(&a);
}

template<typename T>
T* get_pointer(any& a)
{
    assert(can_cast<T>(a));
    return any_cast<T>(&a);
}

void case3()
{
    any a;
    int x = 1;
    a = x;
    assert(can_cast<int>(a));
    get<int>(a) = 10;
    *get_pointer<int>(a) = 20;
    cout << any_cast<int>(a) << endl;
}

int main() {
    case3();

    return 0;
}

