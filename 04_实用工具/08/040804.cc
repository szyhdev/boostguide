// g++ 040804.cc -o 040804

#include <iostream>
using namespace std;

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
using namespace boost::uuids;

class uuid_t : public uuid
{
private:
    static random_generator& rand_uuid() {
        static random_generator gen;
        return gen;
    }
    static string_generator& string_uuid() {
        static string_generator gen;
        return gen;
    }

public:
    uuid_t() : uuid(rand_uuid()()) {
    }
    uuid_t(int): uuid(nil_uuid()) {
    }
    uuid_t(const char* str): uuid(string_uuid()(str)) {
    }
    uuid_t(const uuid& u, const char* str) : uuid(name_generator(u)(str)) {
    }
    explicit uuid_t(const uuid& u) : uuid(u) {
    }

    // operator uuid() {
    //     return static_cast<uuid&>(*this);
    // }
    // operator uuid() const {
    //     return static_cast<const uuid&>(*this);
    // }
};

void case5()
{
    uuid_t u0 = 0;
    assert(u0.is_nil());

    uuid_t u1, u2;
    cout << u1 << endl;
    cout << u2 << endl;

    uuid_t u3("{01234567-89ab-cdef-0123-456789abcdef}");
    cout << u3 << endl;

    cout << uuid_t(u3, "test name gen") << endl;
}

int main() {
    case5();

    return 0;
}

