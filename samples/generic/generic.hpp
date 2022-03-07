#ifndef TESTLIB_HPP
#define TESTLIB_HPP

/*
    - Macro BUILD_SHARED_LIB: Macro defined when building the library as shared.
    - Macro IMPORT_DLL: Applications using the shared library on Windows must define this macro.
*/

#if defined(_WIN32) && defined(BUILD_SHARED_LIB)
#define LIBRARY_API __declspec(dllexport)
#define LIBRARY_API_DESC "DLL"
#elif defined(_WIN32) && defined(IMPORT_DLL)
#define LIBRARY_API __declspec(dllimport)
#define LIBRARY_API_DESC ""
#elif defined(__GNUC__) && defined(BUILD_SHARED_LIB)
#define LIBRARY_API __attribute__((visibility("default")))
#define LIBRARY_API_DESC "Shared"
#else
#define LIBRARY_API
#define LIBRARY_API_DESC "Static"
#endif

LIBRARY_API void print_library_type();

#endif  // TESTLIB_HPP