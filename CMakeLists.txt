cmake_minimum_required(VERSION 3.12.4)

add_compile_options("/std:c++latest")

project("RayTracer")
set(TARGET "RayTracer")

set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING INTERNAL FORCE)

file(GLOB HEADERS "RayTracer/include/*.h")
file(GLOB SOURCES "RayTracer/*.cpp" "RayTracer/*/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/RayTracer/include ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty)

add_executable(${TARGET} ${SOURCES} ${HEADERS})