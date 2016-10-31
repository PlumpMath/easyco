cmake_minimum_required(VERSION 2.6)

SET(THIRDPATH ${PROJECT_SOURCE_DIR}/thirdlib)


ADD_DEFINITIONS(-g -std=c++11 -O2 -W -Wall -DCORO_UCONTEXT)


INCLUDE_DIRECTORIES(. ${THIRDPATH}/libev-master/src)

LINK_DIRECTORIES(${THIRDPATH}/libev-master/src/)

LINK_LIBRARIES(pthread dl rt)


ADD_LIBRARY(easyco SHARED
    easyco.cpp
    easyco_sched.cpp
)
