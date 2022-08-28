#ifndef GENERIC_LOADER_HPP
#define GENERIC_LOADER_HPP

// https://docs.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-

#include <windows.h>

#include "generic.hpp"

typedef void (*fp_print_library_type)(void);
typedef GenericClass *(*fp_create_generic_class)(void);
typedef void (*fp_destroy_generic_class)(GenericClass **);

struct GenericLib {
    HINSTANCE hinstance{nullptr};
    fp_print_library_type fn_print_library_type{nullptr};
    fp_create_generic_class fn_create_generic_class{nullptr};
    fp_destroy_generic_class fn_destroy_generic_class{nullptr};
};

#define CHECK_PTR_RV(ptr, rv) \
    if (ptr == nullptr) return rv;

int load_generic_lib(const char *library_path, GenericLib &lib) {
    lib.hinstance = LoadLibrary(library_path);
    CHECK_PTR_RV(lib.hinstance, GetLastError());

    lib.fn_print_library_type = (fp_print_library_type)GetProcAddress(lib.hinstance, "print_library_type");
    CHECK_PTR_RV(lib.fn_print_library_type, GetLastError());

    lib.fn_create_generic_class = (fp_create_generic_class)GetProcAddress(lib.hinstance, "create_generic_class");
    CHECK_PTR_RV(lib.fn_create_generic_class, GetLastError());

    lib.fn_destroy_generic_class = (fp_destroy_generic_class)GetProcAddress(lib.hinstance, "destroy_generic_class");
    CHECK_PTR_RV(lib.fn_destroy_generic_class, GetLastError());

    return 0;
}

void unload_generic_lib(GenericLib &lib) {
    BOOL free = FreeLibrary(lib.hinstance);
    lib = {};
}

class DynamicLibraryBase {
  public:
    virtual ~DynamicLibraryBase() {}

    int load(const char *path) {
        load_library(path);
        get_symbols();
        return 0;
    }

    int unlocad() {
        unload_library();
        return 0;
    }

  protected:
    virtual int load_library(const char *path) = 0;

    virtual int unload_library() = 0;

    virtual int get_symbols() = 0;
};

class DynamicLibraryWindows
{
public:
    virtual ~DynamicLibraryWindows() {}

    protected 
};




#endif  // GENERIC_LOADER_HPP