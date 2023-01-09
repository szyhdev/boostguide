// g++ 030308.cc -o 030308
// valgrind --leak-check=full --show-leak-kinds=all ./030308

#include <iostream>

#include <boost/smart_ptr.hpp>
using namespace boost;

class my_socket {
public:
    int data[10] {0};
    void print() {
        for (auto x: data) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }
};

my_socket* open_my_socket() {
    std::cout << "open_my_socket" << std::endl;
    return new my_socket();
}

void close_my_socket(my_socket* pms) {
    std::cout << "close_my_socket" << std::endl;
    delete pms;
}

void case3()
{
    my_socket* pms = open_my_socket();
    shared_ptr<my_socket> spms(pms, close_my_socket);

    // FILE* pf = fopen("./03/03/030308.cc", "r");  // Resource leak
    shared_ptr<FILE> spfp(fopen("./030308.cc", "r"), fclose);
}

int main() {
    case3();

    return 0;
}

