// g++ 040407.cc -o 040407

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#include <boost/assign.hpp>
using namespace boost::assign;

void case6()
{
    stack<int> stk = (list_of(1), 2, 3).to_adapter();
    stk += 4, 5, 6;
    for (; !stk.empty(); ) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;

    queue<string> q = (list_of("china")("us")("uk")).repeat(2, "russia").to_adapter();
    push(q)("germany");
    for(; !q.empty();) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    priority_queue<double> pq = (list_of(1.414), 1.732, 2.236).to_adapter();
    push(pq), 3.414, 2.71828;
    for(; !pq.empty(); ) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
    case6();

    return 0;
}

