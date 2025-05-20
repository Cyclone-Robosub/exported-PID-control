rm -r build
mkdir build
cd build
cmake ..
make
cd test
./controller_test
