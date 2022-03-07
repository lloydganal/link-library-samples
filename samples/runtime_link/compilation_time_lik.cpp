#include "runtime_linked_lib.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    hello_library();
    std::cout << get_library_name() << std::endl;
    std::cout << is_true(1==0) << std::endl;
    return 0;
}
