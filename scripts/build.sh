#!/usr/bin/env bash
cd "$(dirname "$0")/.."
mkdir -p build && cd build

cmake -DCMAKE_TOOLCHAIN_FILE=../avr-toolchain.cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..
make -j$(nproc)