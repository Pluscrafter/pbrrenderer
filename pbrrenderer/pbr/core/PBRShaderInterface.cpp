/**
 * @file PBRShaderInterface.cpp
 * @brief Defines a wrapper for shaders
 * @author D3PSI
 */
#ifndef PBR_SHADER_INTERFACE_CPP
#define PBR_SHADER_INTERFACE_CPP

#include "PBRShaderInterface.hpp"


std::string pbr::core::PBRShaderInterface::SHADER_BASE_DIR = "shaders/";

pbr::core::PBRShaderInterface::PBRShaderInterface(std::string _shaderSet) {
    this->shaderSet = _shaderSet;
    std::vector< std::string > contents;
    for(const auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator((pbr::core::PBRShaderInterface::SHADER_BASE_DIR 
        + _shaderSet)), {})) {
        std::string path = std::string(entry.path().c_str());
        std::string ext = path.substr(path.find_last_of("."));
        if(ext == ".comp")
            shaderPaths[pbr::util::flags::PBR_COMPUTE_SHADER] = path;
        if(ext == ".vert")
            shaderPaths[pbr::util::flags::PBR_VERTEX_SHADER] = path;
        if(ext == ".frag")
            shaderPaths[pbr::util::flags::PBR_FRAGMENT_SHADER] = path;
        if(ext == ".geom")
            shaderPaths[pbr::util::flags::PBR_GEOMETRY_SHADER] = path;
        if(ext == ".tes")
            shaderPaths[pbr::util::flags::PBR_TESSELATION_EVALUATION_SHADER] = path;
        if(ext == ".tcs")
            shaderPaths[pbr::util::flags::PBR_TESSELETION_CONTROL_SHADER] = path;
    }
    for(const auto& shader : shaderPaths)
        shaders[shader.first] = pbr::util::io::read(shader.second);
}

pbr::core::PBRShaderInterface::~PBRShaderInterface() {
    
}

#endif      // PBR_SHADER_INTERFACE_CPP