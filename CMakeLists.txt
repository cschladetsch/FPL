cmake_minimum_required(VERSION 3.0)

project(FPL)

# used to generate compile options for YouCompleteMe
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
# see https://github.com/sakra/cotire
#include(cotire)

set(CMAKE_CXX_FLAGS "-std=c++14 -g -Wno-deprecated -Wno-switch")
add_definitions(-DFPL_NAMESPACE_NAME=fpl)
add_definitions(-DFPL_DEBUG)
add_definitions(-DFPL_DEBUG_TRACE)

set(ROOT $ENV{ROOT})
set(FPL_ROOT ${CMAKE_SOURCE_DIR})

include_directories(${FPL_ROOT}/include)

set(dir ${FPL_ROOT})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${dir}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${dir}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${dir}/bin")

link_directories(${ROOT}/lib /usr/local/lib)

#macro(def_lang_library name)
#    project(${name}Lang)
#    set(lang_root ${LIBRARY_ROOT}/Language/${name})
#    include_directories(${lang_root}/Include)
#    set(SOURCE_ROOT ${lang_root}/Source/*.cpp)
#    file(GLOB_RECURSE SOURCE_FILES ${SOURCE_ROOT})
#    add_library(${name}Lang ${SOURCE_FILES})
#    cotire(${name}Lang)
#endmacro()

macro(make_library name)
    project(${name})
    set(SOURCE_ROOT ${LIBRARY_ROOT}/${name}/Source/*.cpp)
    file(GLOB_RECURSE SOURCE_FILES ${SOURCE_ROOT})
    add_library(${name} ${SOURCE_FILES} )
    cotire(${name})
endmacro()

#macro(def_platform_library name)
#    project(platform-${name})
#    set(SOURCE_ROOT ${LIBRARY_ROOT}/Platform/${name}/*.cpp)
#    file(GLOB_RECURSE SOURCE_FILES ${SOURCE_ROOT})
#    add_library(platform-${name} SHARED ${SOURCE_FILES})
#    cotire(platform-${name})
#endmacro()

set(TopLevels src test app)
foreach(top ${TopLevels})
    include(${FPL_ROOT}/${top}/CMakeLists.txt)
endforeach()

# TODO
# include(Library/Platform/CMakeLists.txt)
