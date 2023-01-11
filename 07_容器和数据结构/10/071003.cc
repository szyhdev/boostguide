// g++ 071003.cc -o 071003

#include <iostream>
using namespace std;

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
using namespace boost;
using namespace boost::property_tree;
using namespace boost::property_tree::xml_parser;

void print_ptree(ptree& pt) {
    cout << pt.get<string>("conf.theme") << endl;
    cout << pt.get<int>("conf.clock_style") << endl;
    cout << pt.get<long>("conf.gui") << endl;
    for (auto& x: pt.get_child("conf.urls")) {
        cout << x.second.data() << endl;
    }
}

void case2()
{
    ptree pt;
    read_xml("conf.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
    cout << "--------FROM--------" << endl;
    print_ptree(pt);
    cout << "---------TO---------" << endl;
    pt.put("conf.theme", "Matrix Reloaded");
    pt.put("conf.clock_style", 12);
    pt.put("conf.gui", 0);
    pt.put("conf.urls.url", "http://www.url1.org.cn");
    boost::property_tree::xml_writer_settings<string> settings(' ', 4);
    write_xml("conf.xml", pt, std::locale(), settings);
    print_ptree(pt);
    cout << endl;

    read_xml("conf.xml", pt, boost::property_tree::xml_parser::trim_whitespace);
    cout << "--------FROM--------" << endl;
    print_ptree(pt);
    cout << "---------TO---------" << endl;
    pt.put("conf.theme", "matrix");
    pt.put("conf.clock_style", 24);
    pt.put("conf.gui", 1);
    pt.put("conf.urls.url", "http://www.url1.org");
    write_xml("conf.xml", pt, std::locale(), settings);
    print_ptree(pt);
}

int main() {
    case2();

    return 0;
}

