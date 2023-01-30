// g++ 080202.cc -o 080202

#include <iostream>
#include <algorithm>

#include <boost/algorithm/minmax.hpp>
using namespace boost;

void case2() {
    std::string s1("5000"), s2("12345");
    
    // auto x = boost::minmax(s1, s2);
    auto x = std::minmax(s1, s2);
    std::cout << get<0>(x) << " " << get<1>(x) << std::endl;
    std::cout << std::endl;

    auto y = std::minmax({3, 4, 8, 1});
    std::cout << get<0>(y) << " " << get<1>(y) << std::endl;
}

int main() {
    case2();

    return 0;
}

