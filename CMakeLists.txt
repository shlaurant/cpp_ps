cmake_minimum_required(VERSION 3.22)
project(accCpp)

set(CMAKE_CXX_STANDARD 14)

file(GLOB PS_SRCS ps/*.cpp)
foreach (file ${PS_SRCS})
    get_filename_component(fname ${file} NAME)
    string(REPLACE ".cpp" "" name ${fname})
    add_executable(${name} ${file})
endforeach (file ${PS_SRCS})