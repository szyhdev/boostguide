// g++ 030502.cc -o 030502
// valgrind --leak-check=full ./030502

#include <iostream>
using namespace std;

#include <boost/smart_ptr.hpp>
using namespace boost;

struct counted_data {
    int count = 0;
    counted_data() {
        cout << "counted_data()" << endl;
    }
    ~counted_data() {
        cout << "~counted_data()" << endl;
    }
};

void intrusive_ptr_add_ref(counted_data* p) {
    cout << "intrusive_ptr_add_ref: count = " << p->count + 1 << endl;
    ++p->count;
}

void intrusive_ptr_release(counted_data* p) {
    cout << "intrusive_ptr_release: count = " << p->count - 1 << endl;
    if (--p->count == 0) {
        delete p;
    }
}

int main() {
    typedef intrusive_ptr<counted_data> counted_ptr;

    counted_ptr p(new counted_data);
    assert(p);
    assert(p->count == 1);

    counted_ptr p2(p);
    assert(p->count == 2);

    counted_ptr wp(p.get(), false);
    assert(p->count == 2);
    assert(wp->count == 2);

    p2.reset();
    assert(!p2);
    assert(p->count == 1);

    return 0;
}

