cmake_minimum_required(VERSION 3.0.0)
project(link_library_sampes VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17 )
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 17 )
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

include(CheckTypeSize)
CHECK_TYPE_SIZE("void*" PTR_SIZE BUILTIN_TYPES_ONLY)
if (PTR_SIZE EQUAL 8)
  set(PLATFORM_STR "x64")
else ()
  set(PLATFORM_STR "x32")
endif ()

set(ROOT_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../${PLATFORM_STR}/${CMAKE_BUILD_TYPE})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${ROOT_OUTPUT_DIRECTORY}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${ROOT_OUTPUT_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${ROOT_OUTPUT_DIRECTORY}/bin)

function(copy_to_target_build_dir target_name)
    add_custom_command(TARGET ${target_name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${ARGN}
            $<TARGET_FILE_DIR:${target_name}>)
endfunction()

function(symbolic_link_to_build_dir target_name origin destination)
    add_custom_command(TARGET ${target_name}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${origin}
            $<TARGET_FILE_DIR:${TARGET_NAME}>/${destination})
endfunction()

add_subdirectory(samples)