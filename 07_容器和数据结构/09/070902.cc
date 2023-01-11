// g++ 070902.cc -o 070902

#include <iostream>
using namespace std;

#include <boost/multi_array.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;

void case1()
{
    multi_array<int, 3> ma(extents[2][3][4]);

    auto shape = ma.shape();
    for (size_t i = 0; i < ma.num_dimensions(); ++i) {
        cout << shape[i] << " ";
    }
    cout << endl << ma.num_elements() << endl;
    cout << endl;

    for (int i = 0, v = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                ma[i][j][k] = v++;
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                cout << ma[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    std::array<size_t, 3> idx = { 0, 1, 2 };
    ma(idx) = 10;
    cout << ma(idx) << endl;
}

int main() {
    case1();

    return 0;
}

