cmake_minimum_required(VERSION 3.12)
find_package(OpenCV  3.4.16 REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(include_path ${PROJECT_SOURCE_DIR}/include)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(include_path)

add_library(cell SHARED cell.cpp)
add_library(doMap SHARED doMap.cpp)
add_library(show SHARED show.cpp)
add_library(aStar SHARED aStar.cpp)

add_executable(main main.cpp)

target_link_libraries(doMap cell)
target_link_libraries(aStar cell)
target_link_libraries(show ${OpenCV_LIBS})
target_link_libraries(main ${OpenCV_LIBS} cell doMap show aStar)
