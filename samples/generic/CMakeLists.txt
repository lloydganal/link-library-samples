add_library(generic_lib SHARED generic.cpp generic.hpp)
target_compile_definitions(generic_lib PRIVATE BUILD_SHARED_LIB)

add_library(generic_lib_static STATIC generic.cpp generic.hpp)

add_executable(generic generic_main.cpp)
target_link_libraries(generic generic_lib)
target_compile_definitions(generic PRIVATE IMPORT_DLL)

add_executable(generic_static generic_main.cpp)
target_link_libraries(generic_static generic_lib_static)