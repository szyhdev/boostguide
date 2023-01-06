// g++ 040607.cc -o 040607

#include <iostream>
#include <cassert>
using namespace std;

#include <boost/operators.hpp>
using namespace boost;

template<typename T>
class my_smart_array : public indexable<my_smart_array<T>, int, T&>
{
    T* p;
public:
    typedef my_smart_array<T> this_type;
    typedef T* iter_type;

    my_smart_array(T* x) : p(x) {
    }
    ~my_smart_array() {
        delete[] p;
    }
    friend iter_type operator +(const this_type& a, int n) {
        return a.p + n;
    }
};

void case6()
{
    my_smart_array<double> ma(new double[10]);
    ma[0] = 1.0;
    *(ma + 1) = 2.0;
    cout << ma[1] << endl;
}

int main() {
    case6();

    return 0;
}

