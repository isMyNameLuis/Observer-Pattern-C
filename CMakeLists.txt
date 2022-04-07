cmake_minimum_required(VERSION 3.0.0)
project(observer_pattern VERSION 0.1.0)

include(CTest)
enable_testing()

#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCES
${CMAKE_CURRENT_SOURCE_DIR}/std_includes.h
${CMAKE_CURRENT_SOURCE_DIR}/observer.c
${CMAKE_CURRENT_SOURCE_DIR}/observer.h
${CMAKE_CURRENT_SOURCE_DIR}/provider.c
${CMAKE_CURRENT_SOURCE_DIR}/provider.h
)

add_executable(observer_pattern main.c ${SOURCES})
target_include_directories(observer_pattern PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)