// g++ 080201.cc -o 080201

#include <iostream>
using namespace std;

#include <boost/algorithm/minmax.hpp>
using namespace boost;

void case1() {
    cout << std::min(200, 12) << " " << std::max(200, 12) << endl;
    cout << endl;

    auto x = boost::minmax(200, 12);
    cout << boost::get<0>(x) << " " << boost::get<1>(x) << endl;
}

int main() {
    case1();

    return 0;
}

