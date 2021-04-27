#!/bin/sh

set -x

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-./build}
BUILD_TYPE=${BUILD_TYPE:-release}
CXX=${CXX:-g++}

cd $BUILD_DIR \
    && cmake \
    -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
    $SOURCE_DIR \
    && make $*
    cp  $SOURCE_DIR/index.html ./bin
    mkdir -p ./bin/fileStorage
