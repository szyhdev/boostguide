// g++ 070603.cc -o 070603

#include <iostream>
#include <vector>
using namespace std;

#include <boost/core/ignore_unused.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
using namespace boost;

typedef boost::tuple<int, string, double> my_tuple;
typedef boost::tuple<void> no_instance_tuple1;
typedef boost::tuple<int()> no_instance_tuple2;

void case1()
{
    typedef boost::tuple<int, std::string, double> my_tuple;
    my_tuple t1;
    cout << t1 << endl;
    my_tuple t2(1, "123");
    cout << t2 << endl;
    my_tuple t3(t1);
    cout << t3 << endl;
    t2 = t3;
    cout << t2 << endl;
    cout << endl;

    int x = 10;
    boost::tuple<int&> t4(x);
    cout << t4 << endl;
    cout << endl;

    {
        boost::tuple<void*> t1;
        boost::tuple<double(*)(int)> t2;
    }

    {
        cout << boost::make_tuple(2, 3.0) << endl;
        boost::make_tuple(std::string(), std::vector<int>());

        int i;
        std::string s;
        boost::tuple<int, std::string&> t1 = boost::make_tuple(i, boost::ref(s));
        boost::tuple<const int&, std::string&> t2 = boost::make_tuple(boost::cref(i), boost::ref(s));

	boost::ignore_unused(t1, t2);
    }
}

int main() {
    case1();

    return 0;
}

