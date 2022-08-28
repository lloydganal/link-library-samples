#ifndef DYNAMIC_LIBRARY_HPP
#define DYNAMIC_LIBRARY_HPP

#include <windows.h>

#include <cstdint>

struct DynamicLibrary {
    HINSTANCE hinstance = NULL;
    BOOL loaded = FALSE;
};

int32_t dynlib_load_library(const char* path, DynamicLibrary& lib) {
    lib.hinstance = LoadLibrary(path);
    if (lib.hinstance == NULL) {
        return GetLastError();
    }
    lib.loaded = TRUE;
    return 0;
}

int32_t dynlib_unload_library(DynamicLibrary& lib) {
    BOOL rv = FreeLibrary(lib.hinstance);
    if (rv == FALSE) {
        return GetLastError();
    }
    lib.hinstance = NULL;
    lib.loaded = FALSE;
    return 0;
}

int32_t dynlib_get_proc_address(DynamicLibrary& lib, const char* name, void** proc_ptr) {
    *proc_ptr = GetProcAddress(lib.hinstance, name);
    if (*proc_ptr == NULL) {
        return GetLastError();
    }
    return 0;
}

const char* dynlib_get_rc_description(int32_t rc) {
    const char* desc;
    switch (rc) {
        case ERROR_MOD_NOT_FOUND: {
            desc = "The specified module could not be found.";
        } break;
        case ERROR_PROC_NOT_FOUND: {
            desc = "The specified procedure could not be found.";
        } break;
        default: {
            desc = "Unknown - See system error documentation.";
        } break;
    }
    return desc;
}

#endif  // DYNAMIC_LIBRARY_HPP