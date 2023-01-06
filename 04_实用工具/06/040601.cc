// g++ 040601.cc -o 040601

#include <iostream>
#include <utility>
#include <cassert>
using namespace std;
using namespace std::rel_ops;

class demo_class
{
private:
    int x;
public:
    demo_class(int n) : x(n) {
    }
    friend bool operator <(const demo_class& l, const demo_class& r) {
        return l.x < r.x;
    }
};

void case1()
{
    demo_class a(10), b(20);

    assert(a < b) ;
    assert(b >= a) ;
}

int main() {
    case1();

    return 0;
}

