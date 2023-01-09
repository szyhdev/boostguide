// g++ 030306.cc -o 030306
// valgrind --leak-check=full ./030306

#include <iostream>

#include <boost/smart_ptr.hpp>
using namespace boost;

class sample {
private:
    class impl;
    shared_ptr<impl> _p;
public:
    sample();
    void print();
};

class sample::impl {
public:
    void print() {
        std::cout << "impl print" << std::endl;
    }
};

sample::sample() : _p(new impl) {
}

void sample::print() {
    _p->print();
}

void case1()
{
    sample s;
    s.print();
}

int main() {
    case1();

    return 0;
}

