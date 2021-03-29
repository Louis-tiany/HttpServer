# Install script for directory: /home/louis/code/project/HttpServer/muduo/net

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/louis/code/project/HttpServer/build/lib/libmuduo_net.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muduo/net" TYPE FILE FILES
    "/home/louis/code/project/HttpServer/muduo/net/Buffer.h"
    "/home/louis/code/project/HttpServer/muduo/net/Callbacks.h"
    "/home/louis/code/project/HttpServer/muduo/net/Channel.h"
    "/home/louis/code/project/HttpServer/muduo/net/Endian.h"
    "/home/louis/code/project/HttpServer/muduo/net/EventLoop.h"
    "/home/louis/code/project/HttpServer/muduo/net/EventLoopThread.h"
    "/home/louis/code/project/HttpServer/muduo/net/EventLoopThreadPool.h"
    "/home/louis/code/project/HttpServer/muduo/net/InetAddress.h"
    "/home/louis/code/project/HttpServer/muduo/net/TcpClient.h"
    "/home/louis/code/project/HttpServer/muduo/net/TcpConnection.h"
    "/home/louis/code/project/HttpServer/muduo/net/TcpServer.h"
    "/home/louis/code/project/HttpServer/muduo/net/TimerId.h"
    )
endif()

