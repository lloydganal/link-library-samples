#include "runtime_linked_lib.hpp"

#include <iostream>

void hello_library() { std::cout << "Hello Library!" << std::endl; }

const char* get_library_name() { return "Runtime linked lib"; }

bool is_true(bool value) { return value; }