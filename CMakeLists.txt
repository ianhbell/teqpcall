cmake_minimum_required(VERSION 3.15...3.27)

project(teqpcall)

set(CMAKE_CXX_STANDARD 20)

set(TEQP_NO_TESTS TRUE CACHE BOOL "No test targets for teqp (quite slow to compile)")
set(TEQP_NO_PYTHON TRUE CACHE BOOL "No pybind11 targets for teqp (quite slow to compile)")
set(TEQP_TEQPC TRUE CACHE BOOL "turn on C interface")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/externals/teqp)

add_executable(teqpccall "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_link_libraries(teqpccall teqpc)
target_include_directories(teqpccall PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/externals/teqp/interface/C")

# Force the teqpc DLL to be placed next to teqpccall executable with MSVC 
if (MSVC)
  set_target_properties( teqpc 
    PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY "$<TARGET_FILE_DIR:teqpccall>"
    RUNTIME_OUTPUT_DIRECTORY "$<TARGET_FILE_DIR:teqpccall>"
  )
endif()