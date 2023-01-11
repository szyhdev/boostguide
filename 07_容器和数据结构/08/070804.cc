// g++ 070804.cc -o 070804

#include <iostream>
using namespace std;

#include <boost/assign.hpp>
#include <boost/variant.hpp>
using namespace boost;

struct var_print : public static_visitor<>
{
    template<typename T>
    void operator ()(T& i) const
    {
        i *= 2;
        cout << i << endl;
    }

    void operator ()(vector<int>& v) const
    {
        v.reserve(v.size() * 2);
        copy(v.begin(), v.end(), back_inserter(v));
        for (auto& x: v) {
            cout << x << " ";
        }
        cout << endl;
    }
};

void case4()
{
    typedef variant<int, double, vector<int>> var_t;

    var_t v(1);
    var_print vp;

    apply_visitor(vp, v);
    v = 3.414;
    apply_visitor(vp, v);

    vector<int> tmp = { 1, 2 };
    v = tmp;
    apply_visitor(vp, v);

    auto vp2 = apply_visitor(vp);
    vp2(v);
}

int main() {
    case4();

    return 0;
}

