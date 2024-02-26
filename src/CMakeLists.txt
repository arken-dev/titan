# ------------------------------------------------------------------------------
#
# Copyright 2016 The Arken Platform Authors.
#
# All rights reserved.
# Use of this source code is governed by a BSD-style
# license that can be found in the LICENSE file.
#
# ------------------------------------------------------------------------------

include_directories(.)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/include)
include_directories(${PROJECT_SOURCE_DIR}/src/lua/json)

link_directories( ${PROJECT_SOURCE_DIR}/deps )

set(SRCS
    Channel.cpp
    Epoll.cpp
    EventLoop.cpp
    EventLoopThread.cpp
    EventLoopThreadPool.cpp
    HttpData.cpp
    #Main.cpp
    Server.cpp
    #ThreadPool.cpp
    Timer.cpp
    Util.cpp
    run.cpp
    httpserver.cpp
    ${PROJECT_SOURCE_DIR}/src/arken/net/httpserver/httpserver.cpp
)

find_package(Qt5Core)
find_package(Qt5Network)
find_package(Qt5Gui)
find_package(Qt5Widgets)


#set(EXECUTABLE_OUTPUT_PATH /home/ariveira/projetos/arken/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/clib/arken/net/HttpServer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC ")

<<<<<<< HEAD
#add_executable(titan ${SRCS})
add_library(
  arken.net.HttpServer.titan SHARED ${SRCS}
)

set_target_properties(arken.net.HttpServer.titan PROPERTIES PREFIX "" OUTPUT_NAME titan)

target_link_libraries(arken.net.HttpServer.titan arken libserver_base)

add_subdirectory(base)
