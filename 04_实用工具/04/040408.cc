// g++ 040408.cc -o 040408

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#include <boost/assign.hpp>
using namespace boost::assign;

void case7()
{
    int a = 1, b = 2, c = 3, d = 4;
    vector<int> v = ref_list_of<4>(a)(b)(c)(d);
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
    assert(v.size() == 4);
}

int main() {
    case7();

    return 0;
}

