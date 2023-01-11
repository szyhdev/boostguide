// g++ 071004.cc -o 071004

#include <iostream>
using namespace std;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
using namespace boost;
using namespace boost::property_tree;
using namespace boost::property_tree::xml_parser;

void case3()
{
    ptree pt;
    read_xml("a.xml", pt, boost::property_tree::xml_parser::trim_whitespace);

    auto pos = pt.find("a");
    cout << pos->second.data() << endl;

    assert(pt.get_optional<string>("a"));
    assert(!pt.get_optional<string>("non_exists"));

    cout << pos->second.get_value_optional<string>().value() << endl;
}

int main() {
    case3();

    return 0;
}

