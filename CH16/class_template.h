#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::string;

template <typename T> class Blob {
public:
    // typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T>);

    size_type size() const {
        return data->size();
    }

    bool empty() const {
        return data->empty();
    }

    // copy version
    void push_back(const T &t) {
        data->push_back(t);
    }

    // move version
    void push_back(T &&t) {
        data->push_back(std::move(t));
    }

    void pop_back();

    T& back();
    T& operator[](size_type);

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type, const string&) const;
};

// member functions: only used functions are instantiated

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {
    cout << "default constructor" << endl;
}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) :
    data(std::make_shared<std::vector<T>>(il)) {
    cout << "initializer_list constructor" << endl;
}

template <typename T>
void Blob<T>::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}
