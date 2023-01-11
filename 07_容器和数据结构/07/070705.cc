// g++ 070705.cc -o 070705

#include <iostream>
using namespace std;

#include <boost/exception/all.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/assign.hpp>
#include <boost/any.hpp>
using namespace boost;

template<typename T>
bool can_cast(any& a)
{
    return typeid(T) == a.type();
}

template<typename T>
T& get(any& a)
{
    assert(can_cast<T>(a));
    return *any_cast<T>(&a);
}

template<typename T>
T* get_pointer(any& a)
{
    assert(can_cast<T>(a));
    return any_cast<T>(&a);
}

template<typename T>
any make_ptr_any(T* p = 0)
{
    return any(boost::shared_ptr<T>(p));
}

template<typename T>
boost::shared_ptr<T>& get_shared(any& a)
{
    assert(can_cast<boost::shared_ptr<T>>(a));
    return *any_cast<boost::shared_ptr<T>>(&a);
}

void case3()
{
    any a = make_ptr_any<string>(new string("long"));
    cout << *get_shared<string>(a) << endl;
    a = make_ptr_any<vector<int>>(new vector<int> { 2, 5, 8 });
    auto v = *get_shared<vector<int>>(a);
    for (auto i: v) {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

template<typename T>
struct any_print
{
    void operator ()(any& a) {
        try
        {
            cout << *any_cast<boost::shared_ptr<T>>(a) << endl; 
        }
        catch (bad_any_cast&)
        {
            cout << "print error" << endl;
        }
    }
};

void case4()
{
    any a;

    a = boost::make_shared<int>(10);
    any_print<int>()(a);

    auto ps = boost::make_shared<string>("metroid");
    a = ps;
    any_print<string>()(a);
}

int main() {
    case3();
    case4();

    return 0;
}

