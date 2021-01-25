@echo off
if not exist build mkdir build
pushd build
cmake ..
cmake --build .
popd
bin\RunSolutions.exe