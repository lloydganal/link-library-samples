#ifndef GENERIC_LOADER_HPP
#define GENERIC_LOADER_HPP

// https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-

#include "dynamic_library.hpp"
#include "generic.hpp"

#define CHECK_RC(rc) \
    if (rc != 0) return rc;

typedef void (*fp_print_library_type)(void);
typedef GenericClass *(*fp_create_generic_class)(void);
typedef void (*fp_destroy_generic_class)(GenericClass **);

struct GenericLib {
    DynamicLibrary lib;
    fp_print_library_type print_library_type{nullptr};
    fp_create_generic_class create_generic_class{nullptr};
    fp_destroy_generic_class destroy_generic_class{nullptr};
};

int generic_lib_load(const char *library_path, GenericLib &lib, ) {
    CHECK_RC(dynlib_load_library(library_path, lib.lib));
    CHECK_RC(dynlib_get_proc_address(lib.lib, "print_library_typ", (void **)&lib.print_library_type));
    CHECK_RC(dynlib_get_proc_address(lib.lib, "create_generic_class", (void **)&lib.create_generic_class));
    CHECK_RC(dynlib_get_proc_address(lib.lib, "destroy_generic_class", (void **)&lib.destroy_generic_class));
    return 0;
}

int generic_lib_unload(GenericLib &lib) {
    CHECK_RC(dynlib_unload_library(lib.lib));
    return 0;
}

#endif  // GENERIC_LOADER_HPP