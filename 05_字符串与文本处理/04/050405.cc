// g++ 050405.cc -o 050405

#include <iostream>
using namespace std;

#include <boost/utility/string_ref.hpp>
#include <boost/algorithm/string.hpp>
using namespace boost;

void case4() {
    string str1("Samus");
    string str2("samus");
    assert(!is_equal()(str1, str2));
    assert(is_less()(str1, str2));
    assert(!is_equal()(str1, string_ref(str2)));
}

int main() {
    case4();

    return 0;
}

