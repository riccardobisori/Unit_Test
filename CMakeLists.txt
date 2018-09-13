cmake_minimum_required(VERSION 3.3)
project(UnitTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
add_subdirectory(lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(UnitTest main.cpp Tests/RGBPixel.cpp Tests/RGBPixel.h Tests/Identity.cpp Tests/Identity.h Tests/Filter.cpp Tests/Filter.h Tests/GrayPixel.cpp Tests/GrayPixel.h Tests/BitmapImage.h Tests/EdgeDetection.h Tests/EdgeDetection.cpp Tests/PPM.h Tests/PPM.cpp Tests/PGM.cpp Tests/PGM.h Tests/Sharpen.cpp Tests/Sharpen.h Tests/Emboss.cpp Tests/Emboss.h Tests/Blur.cpp Tests/Blur.h Tests/test.cpp)
target_link_libraries(UnitTest gtest gtest_main)