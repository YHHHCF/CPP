#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <vector>
using namespace std;

class Screen {
// Allow Window_mgr to access Screen's private members
friend class Window_mgr;

public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos h, pos w, char c) : 
           height(h), width(w), contents(h * w, c) { }

    Screen &display(ostream &os) {
        cout << "non-const display" << endl;
        // 'this' ptr passed to do_display implicitly
        do_display(os);
        return *this;
    }

    // return const object (*this) and
    // take const ptr (this) as implicit argument
    const Screen &display(ostream &os) const {
        cout << "const display" << endl;
        do_display(os);
        return *this;
    }

    // implicit inline
    char get() const {
        return contents[cursor];
    }

    // explicit inline
    inline char get(pos h, pos w) const;

    // explicit inline in definition
    // return a reference of the object itself
    Screen &move(pos r, pos c);

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    string contents;


    // const member function
    void do_display(ostream &os) const {
        os << contents << endl;
    }
};

class Window_mgr {
public:
    using ScreenIndex = vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    vector<Screen> screens{Screen(4, 6, ' ')};

};

// ScreenIndex is defined in Window_mgr
// compiler knows this from Window_mgr::
void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = string(s.height * s.width, ' ');
}

#endif
