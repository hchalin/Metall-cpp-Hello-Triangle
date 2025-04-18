cmake_minimum_required(VERSION 3.15)
project(Tri-Quad-Circle VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Enable debug symbols
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")


add_executable(test
 src/common/vec4.cpp
 src/primative.cpp
 #src/triangle.cpp
 #src/quad.cpp
 src/shaders/readShaderFile.cpp
 src/backend/glfw_adaptor.mm
 src/window.cpp
 src/renderer.cpp
 src/main.cpp
)

# Find GLFW
find_package(glfw3 REQUIRED)

# Include GLFW headers
target_include_directories(test PRIVATE ${GLFW_INCLUDE_DIRS})

# Link GLFW library
target_link_libraries(test PRIVATE glfw)

target_include_directories(test
  PRIVATE
  dependencies
)

find_library(METAL Metal)
find_library(FOUNDATION Foundation)
find_library(QUARTZCORE QuartzCore)
find_library(APPKIT AppKit)

target_link_libraries(test PRIVATE
  stdc++
  "-framework Metal"
  "-framework MetalKit"
  "-framework ModelIO"
  "-framework Foundation"
  "-framework QuartzCore"
  "-framework AppKit" objc
)


