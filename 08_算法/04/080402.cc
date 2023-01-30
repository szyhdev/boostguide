// g++ 080402.cc -o 080402

#include <iostream>
#include <vector>
using namespace std;

#include <boost/algorithm/clamp.hpp>
using namespace boost;
using namespace boost::algorithm;

void case2() {
    vector<int> v = { 2, 4, 6, 8, 10 };
    clamp_range(v, ostream_iterator<int>(cout, " "), 3, 9);
    cout << endl;
}

int main() {
    case2();

    return 0;
}

