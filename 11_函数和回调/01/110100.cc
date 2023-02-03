// g++ 110100.cc -o 110100

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct square
{
    typedef void result_type;
    result_type operator ()(int& x)
    {
        x = x * x;
    }
};

void case1()
{
    vector<int> v = { 1, 2, 3, 4, 5 };
    for_each(v.begin(), v.end(), square());

    for_each(v.begin(), v.end(), [] (const int& x) {
        cout << x << " ";
    });
    cout << endl;
}

int main() {
    case1();

    return 0;
}

