cmake_minimum_required(VERSION 3.17)
project(SFML_Checkers)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_EXE_LINKER_FLAGS "-v")
#set(SFML_DIR "SFML/cmake")

link_directories("SFML/lib")
include_directories("SFML/include")

#find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(SFML_Checkers main.cpp)

target_link_libraries (SFML_Checkers sfml-graphics sfml-window sfml-system)
