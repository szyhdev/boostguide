// g++ 030305.cc -o 030305
// valgrind --leak-check=full ./030305

#include <iostream>
#include <vector>

#include <boost/smart_ptr.hpp>
#include <boost/make_unique.hpp>
using namespace boost;

class my_class {
public:
    std::vector<std::unique_ptr<int>> _v;
};

void unique_ptr_in_container_test()
{
    typedef std::vector<std::unique_ptr<int>> vs;
    vs v(10);
    int i = 0;
    for (auto pos = v.begin(); pos != v.end(); ++pos) {
            (*pos) = boost::make_unique<int>(++i);
        std::cout << *(*pos) << " ";
    }
    std::cout << std::endl;
    v.emplace_back(boost::make_unique<int>(++i));
    for (auto& ptr: v) {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    my_class mc;
}

void case6()
{
    typedef std::vector<shared_ptr<int>> vs;
    vs v(10);
    int i = 0;
    for (auto pos = v.begin(); pos != v.end(); ++pos) {
            (*pos) = make_shared<int>(++i);
        std::cout << *(*pos) << " ";
    }
    std::cout << std::endl;

    for (auto& ptr: v) {
        ptr = make_shared<int>(++i);
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;

    shared_ptr<int> p = v[9];
    *p = 100;
    assert(p.use_count() == 2);
    std::cout << *v[9] << std::endl;
}

int main() {
    unique_ptr_in_container_test();
    case6();

    return 0;
}

