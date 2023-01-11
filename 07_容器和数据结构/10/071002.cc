// g++ 071002.cc -o 071002

#include <iostream>
using namespace std;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
using namespace boost;
using namespace boost::property_tree;

void case1()
{
    ptree pt;
    read_xml("conf.xml", pt);

    cout << pt.get<string>("conf.theme") << endl;
    cout << pt.get<int>("conf.clock_style") << endl;
    cout << pt.get<long>("conf.gui")<< endl;
    cout << pt.get("conf.no_prop", 100) << endl;

    auto child = pt.get_child("conf.urls");
    for (auto& x: child) {
        cout << x.second.get_value<string>() << " ";
    }
    cout << endl;

    for(auto& x : pt.get_child("conf.urls")) {
        cout << x.second.data() << " ";
    }
    cout << endl;
}

int main() {
    case1();

    return 0;
}

