
# Example of calling teqpc from C++

## Clone (recursively)

```
git clone --recursive --shallow-submodules https://github.com/ianhbell/teqpcall.git

## Build and run

```
mkdir bld && cd bld
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release  --target teqpcall
Release/teqpcall
```

To build on all the cores, use ninja as the generator to CMake
```
mkdir bld && cd bld
cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release --target teqpcall
./teqpcall
```
