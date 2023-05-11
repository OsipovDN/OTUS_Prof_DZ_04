cmake_minimum_required (VERSION 3.8)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project (print_ip VERSION ${PROJECT_VESRION})

find_package(GTest)
configure_file(version.h.in version.h)

add_executable (print_ip 
	print_ip.cpp
)

add_executable(print_ip_gtest 
    test/print_ip_gtest.cpp
)

target_include_directories(
    print_ip_gtest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/test
)
target_include_directories(
    print_ip_gtest PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_include_directories(
    print_ip_gtest PRIVATE
    ${GTEST_INCLUDE_DIRS}
)

target_link_libraries(
    print_ip_gtest PRIVATE
    ${GTEST_BOTH_LIBRARIES}
)

set_target_properties(print_ip PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(print_ip PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(print_ip PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)

enable_testing()

add_test(print_ip_gtest print_ip_gtest)

