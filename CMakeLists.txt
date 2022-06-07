cmake_minimum_required(VERSION 3.1)

project(Tutorials VERSION 0.1 LANGUAGES C CXX)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
ExternalProject_Add(SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1
  CMAKE_ARGS
    -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
    -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>
)
ExternalProject_Get_Property(SFML INSTALL_DIR)
set(SFML_LIB ${INSTALL_DIR})

include_directories(${SFML_LIB}/include)
link_directories(${SFML_LIB}/lib)

set(SOURCE
  ./src/main.cpp
  ./src/game.cpp
)

add_executable(FirstApp ${SOURCE})
target_link_libraries(FirstApp optimized sfml-system optimized sfml-window optimized sfml-graphics debug sfml-system-d debug sfml-window-d debug sfml-graphics-d)
