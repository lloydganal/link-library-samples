#include <iostream>

#include "dynamic_library.hpp"
#include "generic.hpp"

typedef void (*fp_print_library_type)(void);
typedef GenericClass *(*fp_create_generic_class)(void);
typedef void (*fp_destroy_generic_class)(GenericClass **);



int main(int argc, char const *argv[]) {
    DynamicLibrary lib;
    int32_t rc = dynlib_load_library("generic_2_lib.dll", lib);
    if (rc != 0) {
        return -1;
    }
    fp_print_library_type fn_print_library_type = nullptr;

    rc = dynlib_get_proc_address(lib, "print_library_typ", (void **)&fn_print_library_type);
    if (rc != 0) {
        return -1;
    }

    fn_print_library_type();

    rc = dynlib_unload_library(lib);
    if (rc != 0) {
        return -1;
    }

    

    return 0;
}
