// g++ 070606.cc -o 070606

#include <iostream>
using namespace std;

#include <boost/assert.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace boost;

typedef boost::tuple<int, double, string> my_tuple;

void case4()
{
    my_tuple t1(1, 2.0, "string");
    std::cout << t1 << std::endl;

    std::cout << "please input tuple: ";
    std::cin >> t1;
    std::cout << t1 << std::endl;

    std::cout << tuples::set_open('[') << tuples::set_close(']');
    std::cout << tuples::set_delimiter(',');
    std::cout << t1 << std::endl;
}

int main() {
    case4();

    return 0;
}

