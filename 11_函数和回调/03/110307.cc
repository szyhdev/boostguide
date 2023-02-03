// g++ 110307.cc -o 110307

#include <iostream>
using namespace std;

#include <boost/bind/bind.hpp>
#include <boost/function.hpp>
using namespace boost;

void call_back_func(int i)
{
    cout << "call_back_func: " << i * 2 << endl;
}

bool case4()
{
    std::function<void(int)> func;

    func = call_back_func;

    // func.clear();  // Compile error
    // func.empty();  // Compile error

    return !!func;
}

int main() {
    cout << case4() << endl;

    return 0;
}

