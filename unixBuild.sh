#!/usr/bin/env bash

rm -rf ./build
rm -rf ./bin
mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build .
cd ..
mkdir bin
mv build/Dev/Client/bin/r-type_client bin/
mv build/Dev/Server/bin/r-type_server bin/
