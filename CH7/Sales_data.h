#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
using namespace std;

class Sales_data {
public:
    Sales_data() = default; // default constructor

    // constructor initializer list
    Sales_data(const string &s, unsigned n, double p) :
               bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(const string &s) : bookNo(s) { }

    // in class init then modified by &is input
    Sales_data(istream &is);

    // const keyword after isbn() means isbn()
    // cannot modify anything from pointer 'this'
    // it means a low level const on pointer 'this'
    // for a const Sales_data object, only with const
    // indicator could isbn be called, otherwise comiple error
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data&);

    Sales_data add(const Sales_data&, const Sales_data&);
    istream &read(istream&, Sales_data&);
    ostream &print(ostream&, Sales_data&);

private:
    double avg_price() const {
        return units_sold ? revenue / units_sold : 0;
    }
    string bookNo;
    unsigned units_sold = 0; // in class init
    double revenue = 0.0;
};

#endif
