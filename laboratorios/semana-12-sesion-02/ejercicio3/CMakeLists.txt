
cmake_minimum_required(VERSION 3.20)
project(ColaImpresion LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CON_SANITIZERS "Activar sanitizers" OFF)

if(CON_SANITIZERS)
    add_compile_options(
        -fsanitize=address,undefined
        -fno-omit-frame-pointer
    )
    add_link_options(
        -fsanitize=address,undefined
    )
endif()

# Ejecutable principal
add_executable(cola main.cpp)
target_compile_options(cola PRIVATE -Wall -Wextra)

# Ejecutable de pruebas
find_package(GTest REQUIRED)

add_executable(pruebas test_cola.cpp)
target_link_libraries(pruebas PRIVATE GTest::gtest_main)
target_compile_options(pruebas PRIVATE -Wall -Wextra)

# Registrar pruebas en CTest
enable_testing()
include(GoogleTest)
gtest_discover_tests(pruebas)


