#ifndef TESTLIB_HPP
#define TESTLIB_HPP

/*
    - Macro BUILD_SHARED_LIB: Macro defined when building the library as shared.
    - Macro IMPORT_DLL: Applications using the shared library on Windows must define this macro.
*/

// clang-format off
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
// clang-format on

class GenericClass {
  public:
    virtual ~GenericClass(){}

    constexpr const char* get_name() const { return m_name; }

  protected:
    constexpr void set_name(const char* name) { m_name = name; }

  private:
    const char* m_name;
};

extern "C" LIBRARY_API void print_library_type();


#ifdef BUILD_SHARED_LIB
extern "C" LIBRARY_API GenericClass *create_generic_class();

extern "C" LIBRARY_API void destroy_generic_class(GenericClass **);
#endif


#endif  // TESTLIB_HPP