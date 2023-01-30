// g++ 080403.cc -o 080403

#include <iostream>
using namespace std;

#include <boost/algorithm/hex.hpp>
#include <boost/exception/all.hpp>
using namespace boost;
using namespace boost::algorithm;

void case1() {
    cout << "123 -> ";
    hex("123", ostream_iterator<char>(cout));
    cout << endl;

    string str;
    cout << "ABC -> ";
    hex("ABC", back_inserter(str));
    cout << str << endl;
    cout << str << " -> ";
    unhex(str, ostream_iterator<char>(cout));
    cout << endl;

    cout << "+-*/ -> ";
    hex("+-*/", ostream_iterator<char>(cout));
    cout << endl;
    cout << "+-*/ -> ";
    hex_lower("+-*/", ostream_iterator<char>(cout));
    cout << endl << endl;
}

void case2() {
    try {
        unhex("3", ostream_iterator<char>(cout));
        unhex("xyz", ostream_iterator<char>(cout));
    }
    catch (const not_enough_input& e) {
        cout << "unhex error: not enough input" << endl;
    }
    catch (const non_hex_input& e) {
        cout << "unhex error: non hex input" << endl;
    }
}

int main() {
    case1();
    case2();

    return 0;
}

