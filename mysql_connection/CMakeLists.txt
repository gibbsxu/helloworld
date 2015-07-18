CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(MYSQL_CONNECTION_USAGE)

SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-g -pipe -W -Wall -fPIC -std=c++11")
SET(WORK_ROOT "../../../")

SET(SRC_LIST mysql_connection_usage.cpp)

INCLUDE_DIRECTORIES(
    "./include"
    "${MYSQL_CONNECTION_USAGE_SOURCE_DIR}/${WORK_ROOT}/third/mysql-connector-c/mysql-connector-c-6.1.6/include"
    "${MYSQL_CONNECTION_USAGE_SOURCE_DIR}/${WORK_ROOT}/google/gtest/gtest-1.6.0/include"
)

LINK_DIRECTORIES(
    "${MYSQL_CONNECTION_USAGE_SOURCE_DIR}/${WORK_ROOT}/google/gtest/gtest-1.6.0/lib"
    "${MYSQL_CONNECTION_USAGE_SOURCE_DIR}/${WORK_ROOT}/third/mysql-connector-c/mysql-connector-c-6.1.6/lib"
)

ADD_DEFINITIONS(
)

ADD_EXECUTABLE(mysql_connection_usage ${SRC_LIST})

TARGET_LINK_LIBRARIES(mysql_connection_usage
    mysqlclient
)

ADD_CUSTOM_COMMAND(
    TARGET mysql_connection_usage
    POST_BUILD
    COMMAND echo "${MYSQL_CONNECTION_USAGE_SOURCE_DIR}"
    COMMAND echo "${MYSQL_CONNECTION_USAGE_BINARY_DIR}"
)
