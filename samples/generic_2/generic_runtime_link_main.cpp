#include <iostream>

#include "generic_loader.hpp"

#define LIBRARY_NAME "generic_2_lib.dll"

int main(int argc, char const* argv[]) {
    GenericLib generic;
    auto ret = generic_lib_load(LIBRARY_NAME, generic);

    if (ret != 0) {
        std::cout << "Error loading library '" << LIBRARY_NAME << "' : (" << ret << ") "
                  << dynlib_get_rc_description(ret) << std::endl;
        return ret;
    }

    generic.print_library_type();

    GenericClass* generic_class = generic.create_generic_class();

    std::cout << generic_class->get_name() << std::endl;

    generic.destroy_generic_class(&generic_class);

    generic_lib_unload(generic);
    return 0;
}
