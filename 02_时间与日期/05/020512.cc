// g++ 020512.cc -o 020512

#include <iostream>
using namespace std;

#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

void case6()
{
    date d(2017, 1, 23);

    date d_start(d.year(), d.month(), 1);
    date d_end = d.end_of_month();

    for (day_iterator d_iter(d_start); d_iter <= d_end; ++d_iter) {
            cout << *d_iter << " " << d_iter->day_of_week() << endl;
    }
    cout << endl;
}

void case7()
{
    date d(2017, 1, 23);

    date d18years = d + years(18);
    cout << d18years << " is " << d18years.day_of_week()<< endl;

    int count = 0;
    for (day_iterator d_iter(date(d18years.year(), 1, 1));
            d_iter <= d18years.end_of_month(); ++d_iter) {
        if (d_iter->day_of_week() == Sunday)
        {
            ++count;
        }
    }
    cout << "Total Sundays = " << count << endl;

    count = 0;
    for (month_iterator m_iter(date(d18years.year(), 1, 1));
            m_iter < date(d18years.year() + 1, 1, 1); ++m_iter) {
        count += m_iter->end_of_month().day();
    }
    cout << "Total days = " << count << " days of year." << endl;
    cout << endl;
}

class credit_card
{
public:
    string bank_name;
    int bill_day_no;

    credit_card(const char* bname, int no) : bank_name(bname), bill_day_no(no) {
    }

    int calc_free_days(date consume_day = day_clock::local_day()) const {
        date bill_day(consume_day.year(), consume_day.month(), bill_day_no);
        if (consume_day > bill_day) {
            bill_day += months(1);
        }

        return (bill_day - consume_day).days() + 20;
    }

    friend bool operator <(const credit_card& l, const credit_card& r) {
        return l.calc_free_days() < r.calc_free_days();
    }
};

void case8()
{
    credit_card a("A bank", 25);
    credit_card b("B bank", 12);

    credit_card tmp = std::max(a, b);
    cout << "You should use " << tmp.bank_name <<
            ", free days = " << tmp.calc_free_days() << endl;
}

int main()
{
    case6();
    case7();
    case8();

    return 0;
}

