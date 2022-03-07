#include <windows.h>

#include <iostream>

typedef void (*ptr_hello_library)(void);
typedef const char *(*ptr_get_library_name)(void);
typedef bool (*ptr_is_true)(bool);

int main(int argc, char const *argv[]) {
    HINSTANCE lib_hinstance;
    BOOL free_rv;
    ptr_hello_library fn_hello_library;
    ptr_get_library_name fn_get_library_name;
    ptr_is_true fn_is_true;

    lib_hinstance = LoadLibrary("runtime_linked_lib.dll");

    if (lib_hinstance == nullptr) {
        return -1;
    }

    fn_hello_library = (ptr_hello_library)GetProcAddress(lib_hinstance, "hello_library");

    if (fn_hello_library != nullptr) {
        fn_hello_library();
    }

    fn_get_library_name = (ptr_get_library_name)GetProcAddress(lib_hinstance, "get_library_name");

    if (fn_get_library_name != nullptr) {
        std::cout << fn_get_library_name() << std::endl;
    }

    fn_is_true = (ptr_is_true)GetProcAddress(lib_hinstance, "is_true");

    if (fn_is_true != nullptr) {
        std::cout << fn_is_true(1==0) << std::endl;
    }

    free_rv = FreeLibrary(lib_hinstance);

    return 0;
}
