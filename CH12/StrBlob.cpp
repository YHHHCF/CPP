#include <iostream>
#include <memory>
#include "StrBlob.h"

using namespace std;

// constructor using initializer list
StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il) :
    data(make_shared<vector<string>>(il)) { }

// check whether index i is in range
void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

void StrBlob::print_addr() const {
    cout << data << endl;
}

void StrBlob::print_size() const {
    cout << data->size() << endl;
}

void StrBlob::print_ref_cnt() const {
    cout << data.use_count() << endl;
}
