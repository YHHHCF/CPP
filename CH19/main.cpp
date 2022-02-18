#include <iostream>
using std::cout; using std::endl;

class Base {
public:
    virtual void print() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived" << endl;
    }
};

int main() {
    // 1. dynamic cast
    // 1.1 for pointers
    // given a Base ptr to Base obj (dynamic type)
    // cannot dynamic_cast it to Derived since it is known that bp1
    // points to Base obj at runtime
    // can static_cast it to Derived
    Base b1;
    Base *bp1 = &b1;
    if (Derived *dp1 = dynamic_cast<Derived*>(bp1)) {
        cout << "debug 1" << endl;
        dp1->print();
    } else {
        cout << "debug 2" << endl; // executed
        bp1->print(); // "Base"
    }

    if (Derived *dp1 = static_cast<Derived*>(bp1)) {
        cout << "debug 3" << endl; // executed
        dp1->print(); // "Base"
    } else {
        cout << "debug 4" << endl;
        bp1->print();
    }

    // given a Derived ptr to Derived obj (dynamic type)
    // can dynamic_cast and static_cast it to Base
    // since Derived to Base casting is always safe when
    // inheritance is public
    Derived d2;
    Derived *dp2 = &d2;
    if (Base *bp2 = dynamic_cast<Base*>(dp2)) {
        cout << "debug 5" << endl; // executed
        bp2->print(); // "Derived"
    } else {
        cout << "debug 6" << endl;
        dp2->print();
    }

    if (Base *bp2 = static_cast<Base*>(dp2)) {
        cout << "debug 7" << endl; // executed
        bp2->print(); // "Derived"
    } else {
        cout << "debug 8" << endl;
        dp2->print();
    }

    // given a Base ptr to Derived obj (dynamic type)
    // can dynamic_cast it to Derived since it is known at runtime
    // that bp3 points to Dynamic object
    // can static_cast it to Derived
    Derived d3;
    Base *bp3 = &d3;
    if (Derived *dp3 = dynamic_cast<Derived*>(bp3)) {
        cout << "debug 9" << endl; // executed
        dp3->print(); // "Derived"
    } else {
        cout << "debug 10" << endl;
        bp3->print();
    }

    if (Derived *dp3 = static_cast<Derived*>(bp3)) {
        cout << "debug 11" << endl; // executed
        dp3->print(); // "Derived"
    } else {
        cout << "debug 12" << endl;
        bp3->print();
    }

    // cannot initialize Derived ptr with Base because it will be undefined
    // when dp4 wants to access members not in Derived but not in Base
    // Base b4;
    // Derived *dp4 = &b4;

    // 1.2 for references
    Base &br1 = b1;
    // Derived &dr1 = dynamic_cast<Derived&>(br1); // bad cast exception
    Derived &dr1 = static_cast<Derived&>(br1);
    dr1.print();

    // 2. typeid
    cout << "====" << endl;
    cout << typeid(b1).name() << endl;
    cout << typeid(bp1).name() << endl;
    cout << typeid(d2).name() << endl;
    cout << typeid(dp2).name() << endl;
    cout << typeid(d3).name() << endl;
    cout << typeid(bp3).name() << endl; // returns static type
    cout << typeid("erbao").name() << endl;
    cout << typeid(10.).name() << endl;
    cout << typeid(10).name() << endl;

    // 3. Enumerations
    enum color {red = 11, green = 33, blue = 55}; // defines a type color
    cout << red << ", " << green << ", " << blue << endl;
    color eye = blue;
    cout << eye << endl;

    cout << typeid(color).name() << endl;
    cout << typeid(eye).name() << endl;
    cout << typeid(red).name() << endl;

    enum class c_color {red = 22, green = 44, blue = 66}; // scoped enumerator
    c_color hair = c_color::red;
    cout << typeid(c_color).name() << endl;
    cout << typeid(blue).name() << endl;
    cout << typeid(c_color::blue).name() << endl;
    int i = blue;
    cout << i << endl;
    // int j = c_color::blue; // cannot implicitly convert to int
    // cout << c_color::blue << endl; // cannot implicitly convert to int

    // 4. union
    union Token {
        char cval;
        int ival;
        float fval;
    };

    Token t1 = {'p'};
    cout << t1.cval << ", " << t1.ival << ", " << t1.fval << endl;
    t1.ival = 121;
    cout << t1.cval << ", " << t1.ival << ", " << t1.fval << endl;
    t1.fval = 19.1;
    cout << t1.cval << ", " << t1.ival << ", " << t1.fval << endl;

    return 0;
}
