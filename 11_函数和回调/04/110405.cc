// g++ 110405.cc -o 110405

#include <iostream>
#include <numeric>
using namespace std;

#include <boost/signals2.hpp>
#include <boost/optional/optional_io.hpp>
using namespace boost::signals2;

template<int N>
struct slots
{
    int operator ()(int x)
    {
        cout << "slot" << N <<" called" << endl;
        return x * N;
    }
};

template<typename T>
class combiner
{
    T v;
public:
    typedef std::pair<T, T> result_type;

    combiner(T t = T()) : v(t) {
        cout << "combiner cosntructor: v = " << v << endl;
    }

    template<typename InputIterator>
    result_type operator ()(InputIterator begin, InputIterator end) const
    {
        if (begin == end)
        {
            return result_type();
        }

        vector<T> vec(begin, end);
        T sum = std::accumulate(vec.begin(), vec.end(), v);
        T max = *std::max_element(vec.begin(), vec.end());

        return result_type(sum, max);
    }
};

void case4()
{
    signal<int(int), combiner<int>> sig;
    // signal<int(int), combiner<int>> sig(combiner<int>(100));

    sig.connect(slots<10>());
    sig.connect(slots<20>());
    sig.connect(slots<30>(), at_front);

    auto x = sig(2);
    cout << x.first << ", " << x.second << endl;
}

int main() {
    case4();

    return 0;
}

