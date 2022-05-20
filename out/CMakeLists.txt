
cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)

project(example)

set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_MACOSX_RPATH TRUE)

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp --std=c++0x -Wno-format -Wno-literal-conversion -Wno-deprecated-register -Wno-return-type")
elseif(UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp --std=c++0x")
endif()

include_directories("/home/jpecquet/miniconda3/envs/puma/include/eigen3/Eigen")
include_directories("/home/jpecquet/miniconda3/envs/puma/include")

add_executable(example example.cpp)

target_link_libraries(example -ldl)
target_link_libraries(example "/home/jpecquet/miniconda3/envs/puma/lib/libPuMA.so"
			      "/home/jpecquet/miniconda3/envs/puma/lib/libtiff.so"
			      "/home/jpecquet/miniconda3/envs/puma/lib/libfftw3_threads.so"
			      "/home/jpecquet/miniconda3/envs/puma/lib/libfftw3.so")
install(TARGETS example DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
