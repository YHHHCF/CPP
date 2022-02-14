#include "Basket.h"

/*
 * this function illustrates dynamic binding on virtual function net_price()
 * the object item must be a ref or ptr on base class instead of a plain object
 * the static type of item is Quote
 * the dynamic type of item is only know at runtime
 * virtual function net_price() must be defined for both base and derived classes
 * since compiler don't know which one is executed at runtime
 */
double print_total(const Quote &item, size_t n) {
    double ret = item.net_price(n);
    cout << item.isbn() << " has total: " << ret << endl;
    return ret;
}

double Basket::total_receipt() const {
    double sum = 0.0;

    // upper_bound returns an iter to the element just past the end of that batch
    // so it will go to the next key
    for (auto iter = items.cbegin(); iter != items.cend();
         iter = items.upper_bound(*iter)) {
        // add all the counts of that key, using virutal call in print_total()
        sum += print_total(**iter, items.count(*iter));
    }
    cout << "Total sale: " << sum << endl;
    return sum;
}
