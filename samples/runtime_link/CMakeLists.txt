add_library(runtime_linked_lib SHARED runtime_linked_lib.cpp runtime_linked_lib.hpp)
target_compile_definitions(runtime_linked_lib PRIVATE LIBRARY_EXPORT)

add_executable(compilation_time_lik compilation_time_lik.cpp)
target_link_libraries(compilation_time_lik runtime_linked_lib)

add_executable(runtime_link runtime_link.cpp)