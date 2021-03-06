cmake_minimum_required(VERSION 3.20)
project(raytracer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

# Set output directory to "/bin"
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/bin")
endforeach()

# Add third-party subdirectories
add_subdirectory("${CMAKE_SOURCE_DIR}/vendor/stb")

# Add search scripts generated by Conan to module path
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
find_package(assimp)

# Define "raytracer" target
file(GLOB_RECURSE TARGET_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.inl"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(raytracer ${TARGET_SOURCES})

target_include_directories(raytracer PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(raytracer stb assimp::assimp)

target_precompile_headers(raytracer PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}/src/pch.hpp"
)
