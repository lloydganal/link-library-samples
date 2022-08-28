#include "generic.hpp"

#include <iostream>

void print_library_type() { std::cout << "Library type : " << LIBRARY_API_DESC << std::endl; }

class GenericClassA : public GenericClass {
  public:
    GenericClassA() { set_name("Lloyd's Class"); }
    virtual ~GenericClassA() {}
};

#ifdef BUILD_SHARED_LIB
GenericClass* create_generic_class() { return new GenericClassA(); }

void destroy_generic_class(GenericClass** gc) {
    delete *gc;
    *gc = nullptr;
}
#endif