cmake_minimum_required (VERSION 3.12)

project (jin)

set (CMAKE_CXX_STANDARD 14)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -03")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set (SFML_ROOT "/usr/include/SFML")

set (SOURCE_FILES
    src/main.cpp
    src/game.cpp
)

set (HEADER_FILES
    include/game.h
)

set (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/make)
find_package (SFML COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
else()
    message(${SFML_INCLUDE_DIR})
    set(SFML_ROOT "" CACHE PATH "SFML top-level directory")
    message("SFML library not found")
endif()

add_executable (program ${SOURCE_FILES ${HEADER_FILES}})
target_link_libraries (program ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})