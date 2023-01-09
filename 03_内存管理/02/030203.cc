// g++ 030203.cc -o 030203
// valgrind --leak-check=full ./030203

#include <iostream>
#include <vector>
using namespace std;

#include <boost/smart_ptr.hpp>
#include <boost/smart_ptr/make_unique.hpp>
using namespace boost;

void case1()
{
    // string* sp(new string("text"));  // Memory leak
    scoped_ptr<string> sp(new string("text"));

    assert(sp);
    assert(sp != nullptr);

    cout << *sp << endl;
    cout << sp->size() << endl;
    cout << endl;
}

struct posix_file {
    posix_file() {
        cout << "open file" << endl;
    }
    posix_file(const char* file_name) {
        cout << "open file: " << file_name << endl;
    }
    ~posix_file() {
        cout << "close file" << endl;
    }
};

void case2()
{
    scoped_ptr<posix_file> fp(new posix_file("/tmp/a.txt"));

    scoped_ptr<int> p(new int);
    if (p) {
        *p = 100;
        cout << *p << endl;
    }
    p.reset();
    assert(p == 0);
    if (!p) {
        cout << "scoped_ptr == nullptr" << endl;
    }
}

class ptr_owned final
{
    scoped_ptr<int> m_ptr;
};

void bad_case()
{
    scoped_ptr<string> sp(new string("text"));
    // sp++;
    // scoped_ptr<string> sp2 = sp;
    // scoped_ptr<string> sp3;
    // sp3 = sp;
    // std::prev(sp);
    // scoped_ptr<string> sp4;
    // if (sp4 == sp) {
    //     cout << "scoped_ptr_1 == scoped_ptr_2" << endl;
    // }

    ptr_owned p;
    // ptr_owned p2(p);
    // ptr_owned p3;
    // p3 = p;

    cout << endl;
}

int main() {
    case1();
    case2();
    bad_case();

    scoped_array<posix_file> sppf(new posix_file[5]);

    return 0;
}

