# Emscripten
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_TOOLCHAIN_FILE emscripten-expose/Emscripten.cmake)
set(CMAKE_C_FLAGS "-O3 -s WASM=1 -s NO_EXIT_RUNTIME=1  -s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\"]'")

# CMakeLists.txt
cmake_minimum_required (VERSION 3.8.2)
project (gpmf-parser)

set(CMAKE_SUPPRESS_REGENERATION true)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

file(GLOB SOURCES GPMF_parser.c "emscripten-expose/*.c")

add_executable(gpmf-parser ${SOURCES})
