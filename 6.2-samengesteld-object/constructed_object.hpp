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
   circle cir1, cir2, cir3;
   line lin1, lin2;
   filled_rectangle rec;
   int modular;
public:
   constructed_object( window & w, int mod);
   void print();
};


#endif // CONSTRUCTED_OBJECT_HPP