// g++ 110105.cc -o 110105

#include <iostream>
using namespace std;

#include <boost/ref.hpp>
using namespace boost;

class big_class {
private:
    int x;
public:
    big_class() : x(0) {
        cout << "Default constructor called" << endl;
    }
    big_class(const big_class& bc){
        x = bc.x;
        cout << "Copy constructor called" << endl;
    }
    void print() {
        std::cout << "big_class " << ++x << std::endl;
    }
};

template<typename T>
void print(T a)
{
    for (int i = 0; i < 2; ++i) {
        unwrap_ref(a).print();
    }
}

void case6()
{
    big_class c;
    auto rw = ref(c);
    c.print();  // ++x -> x == 1
    cout << endl;

    print(c);   // by value: ++x for 2 times -> x == 3
    cout << endl;

    print(rw);  // by reference: ++x for 2 times -> x == 3
    cout << endl;

    print(c);   // by value: ++x for 2 times: x == 5 
    cout << endl;

    c.print();  // ++x -> x == 4
}

int main() {
    case6();

    return 0;
}

