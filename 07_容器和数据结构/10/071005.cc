// g++ 071005.cc -o 071005

#include <iostream>
using namespace std;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace boost;
using namespace boost::property_tree;
using namespace boost::property_tree::xml_parser;
using namespace boost::property_tree::json_parser;

void case3()
{
    ptree pt;
    read_xml("conf.xml", pt);

    cout << pt.get<string>("conf.<xmlcomment>") << endl;
    cout << pt.get<string>("conf.clock_style.<xmlattr>.name") << endl;
    cout << pt.get<long>("conf.theme.<xmlattr>.id") << endl;
    cout << pt.get<string>("conf.urls.<xmlcomment>") << endl;
    cout << endl;
}

void case4()
{
    ptree pt;
    read_json("conf.json", pt);

    cout << pt.get<string>("conf.theme") << endl;
    cout << pt.get<int>("conf.clock_style") << endl;
    cout << pt.get<long>("conf.gui") << endl;
    cout << pt.get("conf.no_prop", 100) << endl; 

    for (auto& x: pt.get_child("conf.urls")) {
        cout << x.second.data() << " ";
    }
}

int main() {
    case3();
    case4();

    return 0;
}

