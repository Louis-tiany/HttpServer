# Install script for directory: /home/louis/code/project/HttpServer/muduo/base

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/louis/code/project/HttpServer/build/lib/libmuduo_base.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muduo/base" TYPE FILE FILES
    "/home/louis/code/project/HttpServer/muduo/base/AsyncLogging.h"
    "/home/louis/code/project/HttpServer/muduo/base/Atomic.h"
    "/home/louis/code/project/HttpServer/muduo/base/BlockingQueue.h"
    "/home/louis/code/project/HttpServer/muduo/base/BoundedBlockingQueue.h"
    "/home/louis/code/project/HttpServer/muduo/base/Condition.h"
    "/home/louis/code/project/HttpServer/muduo/base/CountDownLatch.h"
    "/home/louis/code/project/HttpServer/muduo/base/CurrentThread.h"
    "/home/louis/code/project/HttpServer/muduo/base/Date.h"
    "/home/louis/code/project/HttpServer/muduo/base/Exception.h"
    "/home/louis/code/project/HttpServer/muduo/base/FileUtil.h"
    "/home/louis/code/project/HttpServer/muduo/base/GzipFile.h"
    "/home/louis/code/project/HttpServer/muduo/base/LogFile.h"
    "/home/louis/code/project/HttpServer/muduo/base/LogStream.h"
    "/home/louis/code/project/HttpServer/muduo/base/Logging.h"
    "/home/louis/code/project/HttpServer/muduo/base/Mutex.h"
    "/home/louis/code/project/HttpServer/muduo/base/ProcessInfo.h"
    "/home/louis/code/project/HttpServer/muduo/base/Singleton.h"
    "/home/louis/code/project/HttpServer/muduo/base/StringPiece.h"
    "/home/louis/code/project/HttpServer/muduo/base/Thread.h"
    "/home/louis/code/project/HttpServer/muduo/base/ThreadLocal.h"
    "/home/louis/code/project/HttpServer/muduo/base/ThreadLocalSingleton.h"
    "/home/louis/code/project/HttpServer/muduo/base/ThreadPool.h"
    "/home/louis/code/project/HttpServer/muduo/base/TimeZone.h"
    "/home/louis/code/project/HttpServer/muduo/base/Timestamp.h"
    "/home/louis/code/project/HttpServer/muduo/base/Types.h"
    "/home/louis/code/project/HttpServer/muduo/base/WeakCallback.h"
    "/home/louis/code/project/HttpServer/muduo/base/copyable.h"
    "/home/louis/code/project/HttpServer/muduo/base/noncopyable.h"
    )
endif()

