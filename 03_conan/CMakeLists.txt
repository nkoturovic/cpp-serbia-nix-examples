cmake_minimum_required(VERSION 3.15)

project(HelloCppSerbia)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
# find_package(spdlog REQUIRED)

# include_directories(${SDL2_INCLUDE_DIRS})

# include(${CMAKE_BINARY_DIR}/conanbuildinfo.txt)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(hello_cpp_serbia src/main.cpp)
target_link_libraries(hello_cpp_serbia PRIVATE 
    ${SDL2_LIBRARIES}
    SDL2_ttf::SDL2_ttf
    ${CONAN_LIBS}
)
