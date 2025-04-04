#pragma once
// Include Apple's framework headers for Metal and related APIs
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>
#include <AppKit/AppKit.hpp>

#include "window.h"
//#include "triangle.h"
//#include "quad.h"
#include "primative.h"

#include <iostream>

class Renderer
{
public:
  Renderer(Window &window);
  ~Renderer();

  // Getter
  MTL::Device *getDevice();

  // Render method
  void render();

private:
  void logFPS();
  MTL::Device *device;
  MTL::CommandQueue *commandQueue;
  Window &window;

  // Scene objects
  //Triangle *triangle;
  //Quad* quad;

  // New objs using abc
  Primative* triangle;    // Base ptr
  Primative* quad;
  Primative* circle;

  std::chrono::high_resolution_clock::time_point previousTime;
  double totalTime;
  int lastPrintedSecond;
  int frames;
};
