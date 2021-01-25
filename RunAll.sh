#!/bin/bash

set -e
mkdir -p build
pushd build
cmake ..
cmake --build .
popd
./bin/RunSolutions