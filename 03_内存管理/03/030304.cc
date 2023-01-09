// g++ 030304.cc -o 030304
// valgrind --leak-check=full ./030304

#include <iostream>
#include <vector>

#include <boost/smart_ptr.hpp>
using namespace boost;

void case5()
{
    auto sp = make_shared<std::string>("make_shared");
    std::cout << *sp << std::endl;

    auto spv = make_shared<std::vector<int>>(10, 2);
    std::cout << spv->size() << std::endl;

    for (auto i = 0; i < spv->size(); i++) {
        std::cout << (*spv)[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    case5();

    return 0;
}

