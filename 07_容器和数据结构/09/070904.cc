// g++ 070904.cc -o 070904

#include <iostream>
using namespace std;

#include <boost/multi_array.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;

void case3()
{
    typedef multi_array<int, 2> ma_type;
    multi_array<int, 2> ma(extents[3][4]) ;

    for (int i = 0, v = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            ma[i][j] = v++;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << ma[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    typedef ma_type::index_range range;
    auto view = ma[indices[range(0, 2)][range(0, 2)]];

    cout << view.num_elements() << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << view[i][j] << " ";
        }
        cout << endl;
    }
    cout << *view.shape() << endl;
}

int main() {
    case3();

    return 0;
}

