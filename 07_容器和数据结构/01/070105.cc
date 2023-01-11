// g++ 070103.cc -o 070103

#include <iostream>

#include <boost/array.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;

void case2()
{
    array<std::string, 3> ar = {"alice","bob", "carl"};

    int a[10] = {0};
    array<int, 10> ar1 = {0};
    assert(std::equal(ar1.begin(), ar1.end(), a));

    array<std::string, 3> ar2 = {"racer"};
    assert(ar2.at(1).empty());

    array<int, 3> arr(list_of(2)(4)(6)) ;
    for (auto i = 0u; i< arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    case2();

    return 0;
}

