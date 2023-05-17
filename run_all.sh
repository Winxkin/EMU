echo "Building project"
cmake -Bbuild

echo "Making"
cd build
make -j4
cd ..

echo "executing target"
./build/main