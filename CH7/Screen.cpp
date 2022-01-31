#include "Screen.h"

char Screen::get(pos r, pos c) const {
    return contents[r * width + c];
}

// inline in definition
inline Screen &Screen::move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
}
