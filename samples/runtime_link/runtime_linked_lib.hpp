#ifndef RUNTIME_LINKED_LIB_HPP
#define RUNTIME_LINKED_LIB_HPP

#ifdef LIBRARY_EXPORT
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)
#endif

extern "C" LIBRARY_API void hello_library();

extern "C" LIBRARY_API const char * get_library_name();

extern "C" LIBRARY_API bool is_true(bool value);

#endif // RUNTIME_LINKED_LIB_HPP