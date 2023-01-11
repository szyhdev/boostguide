// g++ 070905.cc -o 070905

#include <iostream>
using namespace std;

#include <boost/multi_array.hpp>
#include <boost/assign.hpp>
using namespace boost;
using namespace boost::assign;

void case4()
{
    int arr[12];
    for (int i = 0; i < 12; ++i) {
        arr[i] = i;
    }

    multi_array_ref<int, 2> mar(arr, extents[3][4]);
    for (size_t i = 0; i < 3; ++i) {
        cout << "(";
        for (size_t j = 0; j < 4; ++j) {
            cout << mar[i][j]++;
            cout << (j != 3 ? "," : "");
        }
        cout << ")" << endl;
    }
    cout << endl;

    const_multi_array_ref<int, 2> cmar(arr, extents[2][6]);
    for (size_t i = 0; i < 2; ++i) {
        cout << "(";
        for (size_t j = 0; j < 6; ++j) {
            cout << cmar[i][j];
            cout << (j != 5 ? "," : "");
        }
        cout << ")" << endl;
    }
}

int main() {
    case4();

    return 0;
}

