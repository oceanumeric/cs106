cmake_minimum_required(VERSION 2.8.9)

set(LIBRARY_NAME stanford)

set(HOME "$ENV{HOME}")

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support.
        Please use a different C++ compiler.")
endif()


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


include_directories(lib)
include_directories(lib/collections)
include_directories(lib/graphics)
include_directories(lib/io)
include_directories(lib/private)
include_directories(lib/system)
include_directories(lib/util)

file(GLOB_RECURSE LIB_FILES lib/*.cpp)

add_library(${LIBRARY_NAME} STATIC ${LIB_FILES})

install(TARGETS ${LIBRARY_NAME} DESTINATION ${HOME}/stanford)