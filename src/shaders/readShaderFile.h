#pragma once

std::string readShaderFile(const std::string &filePath);
// void loadShaderFromFile(MTL::Device *device, const std::string &filePath);
void loadShaderFromFile(MTL::Library *&inLib, MTL::Device *device, const std::string &filePath);
