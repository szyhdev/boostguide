// g++ 050106.cc -o 050106

#include <iostream>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

void case4() {
    cout << "stoi(\"  42 \") == 42" << endl;
    assert(stoi("  42 ") == 42);
    cout << "stol(\"100L\") == 100" << endl;
    assert(stol("100L") == 100L);
    cout << "stoll(\"1000L 9\") == 1000" << endl;
    assert(stoll("1000L 9") == 1000L);
    cout << "stof(\"3.14ispi\") == " << stof("3.14ispi") << endl;
    assert(fabs(stof("3.14ispi") - 3.14) < numeric_limits<float>::epsilon());
    cout << "stod(\"3.1415926535\") == 3.1415926535" << endl;
    assert(fabs(stod("3.1415926535") - 3.1415926535) < numeric_limits<double>::epsilon());
    cout << "to_string(776ul) == " << to_string(776ul) << endl;
    assert(to_string(776ul) == "776");
    cout << endl;

    try {
        cout << stoul("x100") << endl;
    }
    catch (invalid_argument& e) {
        cout << "exception caught: " << e.what() << endl;
    }
    try {
        cout << stoi("9999999999") << endl;
    }
    catch (out_of_range& e) {
        cout << "exception caught: " << e.what() << endl;
    }
}

template<typename T>
T std_lexical_cast(const string& s);

template<>
int std_lexical_cast<int>(const string& s) {
    return stoi(s);
}

template<>
long std_lexical_cast<long>(const string& s) {
    return stol(s);
}

void case5() {
    assert(std_lexical_cast<int>("  42 ") == 42);
    assert(std_lexical_cast<long>("100L") == 100L);
}

int main() {
    case4();
    case5();

    return 0;
}

