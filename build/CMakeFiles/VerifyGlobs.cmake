# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.20
cmake_policy(SET CMP0009 NEW)

# TARGET_SOURCES at CMakeLists.txt:9 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/home/rayferric/Source/raytracer/src/*.cpp")
set(OLD_GLOB
  "/home/rayferric/Source/raytracer/src/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/rayferric/Source/raytracer/build/CMakeFiles/cmake.verify_globs")
endif()

# TARGET_SOURCES at CMakeLists.txt:9 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/home/rayferric/Source/raytracer/src/*.hpp")
set(OLD_GLOB
  "/home/rayferric/Source/raytracer/src/image.hpp"
  "/home/rayferric/Source/raytracer/src/texture.hpp"
  "/home/rayferric/Source/raytracer/src/vec2.hpp"
  "/home/rayferric/Source/raytracer/src/vec3.hpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/home/rayferric/Source/raytracer/build/CMakeFiles/cmake.verify_globs")
endif()
