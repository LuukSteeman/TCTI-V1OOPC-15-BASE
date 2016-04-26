// example:
// declaration of a constructed object

#ifndef CONSTRUCTED_OBJECT_HPP
#define CONSTRUCTED_OBJECT_HPP

#include "window.hpp"
#include "filled_rectangle.hpp"
#include "circle.hpp"
#include "line.hpp"

class constructed_object {
private:
   window &win;
   circle &cir;
   line &lin;
   filled_rectangle &rec;
public:
   constructed_object( window & w, circle & cir, line & lin, filled_rectangle & rec);
   void print();
};


#endif // CONSTRUCTED_OBJECT_HPP
