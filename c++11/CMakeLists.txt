CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(grammer)

SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-g -O2 -pipe -W -Wall -fPIC -std=c++11")
SET(WORK_ROOT "../../..")

SET(GRAMMER_SRC_LIST grammer.cpp)
SET(SMART_PTR_SRC_LIST smart_ptr_usage.cpp)
SET(MOVE_SRC_LIST move_usage.cpp)
SET(CONTAINER_SRC_LIST container_usage.cpp)
SET(THREAD_SRC_LIST thread_usage.cpp)
SET(REGEX_SRC_LIST regex_usage.cpp)
SET(RANDOM_SRC_LIST random_usage.cpp)

INCLUDE_DIRECTORIES(
    "./include"
    "${grammer_SOURCE_DIR}/${WORK_ROOT}/google/gtest/gtest-1.6.0/include"
)

LINK_DIRECTORIES(
    "${grammer_SOURCE_DIR}/${WORK_ROOT}/google/gtest/gtest-1.6.0/lib"
)

ADD_DEFINITIONS(
)

ADD_EXECUTABLE(grammer ${GRAMMER_SRC_LIST})
ADD_EXECUTABLE(smart_ptr_usage ${SMART_PTR_SRC_LIST})
ADD_EXECUTABLE(move_usage ${MOVE_SRC_LIST})
ADD_EXECUTABLE(container_usage ${CONTAINER_SRC_LIST})
ADD_EXECUTABLE(thread_usage ${THREAD_SRC_LIST})
ADD_EXECUTABLE(regex_usage ${REGEX_SRC_LIST})
ADD_EXECUTABLE(random_usage ${RANDOM_SRC_LIST})



ADD_CUSTOM_COMMAND(
    TARGET grammer
    POST_BUILD
    COMMAND echo "${grammer_SOURCE_DIR}"
    COMMAND echo "${grammer_BINARY_DIR}"
)
