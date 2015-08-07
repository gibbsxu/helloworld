CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(BOOST_ASSIGN)

SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-g -pipe -W -Wall -fPIC -Wno-unused-parameter")
SET(WORK_ROOT "../../../..")

SET(PRODUCER_CONSUMER_MUTLITHREAD producer_consumer_mutlithread.cpp)
SET(PRODUCER_CONSUMER_COROUTINE producer_consumer_coroutine.cpp)
SET(PRODUCER_CONSUMER_COROUTINE2 producer_consumer_coroutine2.cpp)
SET(PRODUCER_CONSUMER_SIGNAL producer_consumer_signal.cpp)

INCLUDE_DIRECTORIES(
    "./include"
    "${BOOST_ASSIGN_SOURCE_DIR}/${WORK_ROOT}/third/boost/boost-1.58.0/include"
)

LINK_DIRECTORIES(
    "${BOOST_ASSIGN_SOURCE_DIR}/${WORK_ROOT}/third/boost/boost-1.58.0/lib"
)

ADD_DEFINITIONS(
)

ADD_EXECUTABLE(producer_consumer_mutlithread ${PRODUCER_CONSUMER_MUTLITHREAD})
ADD_EXECUTABLE(producer_consumer_coroutine ${PRODUCER_CONSUMER_COROUTINE})
ADD_EXECUTABLE(producer_consumer_coroutine2 ${PRODUCER_CONSUMER_COROUTINE2})
ADD_EXECUTABLE(producer_consumer_signal ${PRODUCER_CONSUMER_SIGNAL})

TARGET_LINK_LIBRARIES(producer_consumer_mutlithread
    boost_thread boost_system)
TARGET_LINK_LIBRARIES(producer_consumer_coroutine
    boost_thread boost_system boost_timer libboost_coroutine.dylib)
TARGET_LINK_LIBRARIES(producer_consumer_coroutine2
    boost_thread boost_system boost_timer libboost_coroutine.dylib)
TARGET_LINK_LIBRARIES(producer_consumer_signal
    boost_thread boost_system boost_signals)
