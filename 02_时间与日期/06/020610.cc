// g++ 020610.cc -o 020610

#include <iostream>
using namespace std;

#define BOOST_DATE_TIME_POSIX_TIME_STD_CONFIG

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;

template<typename Clock = microsec_clock>
class basic_ptimer {
public:
    basic_ptimer() {
        restart();
    }
    void restart() {
        _start_time = Clock::local_time();
    }
    void elapsed() const {
        cout << Clock::local_time() - _start_time << endl;
    }
    ~basic_ptimer() {
        elapsed();
    }
private:
    ptime _start_time;
};

typedef basic_ptimer<microsec_clock> ptimer;
typedef basic_ptimer<second_clock> sptimer;

class work_time
{
public:
    typedef map<time_period, string> map_t;
private:
    map_t map_ts;
    void init() {
        ptime p(day_clock::local_day());

        map_ts[time_period(p, hours(9))] = "It's too early, just relax.";
        p += hours(9);
        map_ts[time_period(p, hours(3) + minutes(30))] = "It's AM, please work hard.";
        p += hours(3) + minutes(30);
        map_ts[time_period(p, hours(1))] = "It's lunch time, are you hungry?";
        p += hours(1);
        map_ts[time_period(p, hours(4)+minutes(30))] = "It's PM, ready to go home.";
        p += hours(4) + minutes(30);
        map_ts[time_period(p, hours(6))] = "Are you still working? you do need a rest.";
    }
public:
    work_time() {
        init();
    }

    void greeting(const ptime& t) {
        for (auto& x: map_ts) {
            if (x.first.contains(t)) {
                cout << x.second << endl;
                break;
            }
        }
    }
};

void case10()
{
    ptimer t;

    work_time wt;
    wt.greeting(second_clock::local_time());
}

int main()
{
    case10();

    return 0;
}

