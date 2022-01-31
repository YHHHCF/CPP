#include "Sales_data.h"

Sales_data::Sales_data(istream &is) {
    read(is, *this);
}

Sales_data& Sales_data::combine(const Sales_data &s) {
 units_sold += s.units_sold;
 revenue += s.revenue;
 return *this; // (*this) get a lvalue, returned as reference
}

Sales_data Sales_data::add(const Sales_data &s1, const Sales_data &s2) {
 Sales_data sum = s1;
 sum.combine(s2);
 return sum; // return rvalue
}

istream& Sales_data::read(istream &is, Sales_data &s) {
    double price = 0;
    is >> s.bookNo >> s.units_sold >> price;
    s.revenue = price * s.units_sold;
    return is;
}

ostream& Sales_data::print(ostream &os, Sales_data &s) {
 os << s.isbn() << " " << s.units_sold << " "
    << s.revenue << " " << s.avg_price();
 return os;
}
