// g++ 020704.cc -o 020704

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time/local_time.hpp>
using namespace boost::gregorian;
using namespace boost::posix_time;
using namespace boost::local_time;

void case3()
{
    tz_database tz_db;
    tz_db.load_from_file("./date_time_zonespec.csv");

    time_zone_ptr shz = tz_db.time_zone_from_region("Asia/Shanghai");
    time_zone_ptr sfz = tz_db.time_zone_from_region("America/Los_Angeles");

    cout << shz->has_dst() << endl;
    cout << shz->std_zone_name() << endl;

    local_date_time dt_bj(date(2014, 3, 6), hours(16), shz, false);
    cout << dt_bj << endl;

    time_duration flight_time = hours(12);
    dt_bj += flight_time;
    cout << dt_bj << endl;
    local_date_time dt_sf = dt_bj.local_time_in(sfz);
    cout << dt_sf << endl;
}

int main()
{
    case3();

    return 0;
}

