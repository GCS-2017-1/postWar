cmake_minimum_required (VERSION 3.0.2)
project(postwar LANGUAGES CXX C)



message(STATUS "1")

set( INCLUDE_DIR "${PROJECT_SOURCE_DIR}" )
set( SRC_DIR "${PROJECT_SOURCE_DIR}/sources" )
set( SOUNDS_DIR "${PROJECT_SOURCE_DIR}/sounds" )

message(STATUS "2")

file(GLOB_RECURSE SOURCES "*.cpp"
                          "*.c")


message(STATUS "3")

include_directories(${INCLUDE_DIR}/include ${INCLUDE_DIR}/source/RenderWorld)

message(STATUS "4")
set(COMPILE_FLAGS "")
set(COMPILE_FLAGS "${COMPILE_FLAGS} -Wall -W -pedantic -ansi -lm")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS}")
message(STATUS "5")

add_executable(postwar ${SOURCES})
message(STATUS "6")

target_link_libraries(postwar lSDL lSDL_image lSDL_net lSDL_ttf lSDL_mixer)
message(STATUS "7")

add_custom_command(TARGET postwar POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${SOUNDS_DIR} ${CMAKE_BINARY_DIR}/sounds)
message(STATUS "8")
