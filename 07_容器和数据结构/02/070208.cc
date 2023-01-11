// g++ 070208.cc -o 070208

#include <iostream>
using namespace std;

#include <boost/dynamic_bitset.hpp>
#include <boost/utility.hpp>
using namespace boost;

void prime_number(int n)
{
    dynamic_bitset<> db(n);
    db.set();

    for (auto i = db.find_next(1); i != dynamic_bitset<>::npos; i = db.find_next(i)) {
        for (auto j = db.find_next(i); j != dynamic_bitset<>::npos; j = db.find_next(j)) {
            if ( j % i == 0) {
                db[j] = 0;
            }
        }
    }

    cout << dec;
    for (auto i = db.find_next(2); i != dynamic_bitset<>::npos; i = db.find_next(i)) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    prime_number(10);
    prime_number(50);

    return 0;
}

