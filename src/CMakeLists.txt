cmake_minimum_required(VERSION 3.21.2)

project(vehicle_path_planning CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# enable repository specific options
# include("${CMAKE_CURRENT_SOURCE_DIR}/../cmake/ProjectSpecificOptions.cmake")

add_subdirectory(utils)
# add_subdirectory(planning)

# add includes for this project
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/conf
    ${CMAKE_CURRENT_SOURCE_DIR}/map
    ${CMAKE_CURRENT_SOURCE_DIR}/planner)

set(SOURCES_CPP
    ${CMAKE_CURRENT_SOURCE_DIR}/map/grid_map.cpp
    main.cpp)

set(EXECUTABLE_OUTPUT_PATH "../bin")


add_executable(${PROJECT_NAME} ${SOURCES_CPP})
target_link_libraries(${PROJECT_NAME} utils)