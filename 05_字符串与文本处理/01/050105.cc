// g++ 050105.cc -o 050105

#include <iostream>
using namespace std;

#include <boost/lexical_cast.hpp>
using namespace boost;

class demo_class {
    friend ostream& operator <<(ostream& os, const demo_class& x) {
        os << "demo_class's name";
        return os;
    }
};

template<typename T>
struct outable {
    friend ostream& operator <<(ostream& os, const T& x) {
        os << typeid(T).name();
        return os;
    }
};

class demo_class_2 : outable<demo_class_2> {
public:
    demo_class_2() : data_(0) {
    }
private:
    int data_;
};

class demo_class_3 : outable<demo_class_3> {
public:
    demo_class_3() : data_("string") {
    }
private:
    string data_;
};

void case3()
{
    cout << lexical_cast<string>(demo_class()) << endl;
    cout << lexical_cast<string>(demo_class_2()) << endl;
    cout << lexical_cast<string>(demo_class_3()) << endl;
}

int main() {
    case3();

    return 0;
}

