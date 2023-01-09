// g++ 030503.cc -o 030503
// valgrind --leak-check=full ./030503

#include <iostream>

#include <boost/smart_ptr.hpp>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>

using namespace std;
using namespace boost;

struct counted_data : public intrusive_ref_counter<counted_data>
{
    int count = 0;
    counted_data() {
        cout << "counted_data()" << endl;
    }
    ~counted_data() {
        cout << "~counted_data()" << endl;
    }
};

int main() {
    typedef intrusive_ptr<counted_data> counted_ptr;

    counted_ptr p(new counted_data);
    assert(p);
    assert(p->use_count() == 1);

    return 0;
}

