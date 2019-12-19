/**
 * @file PBRShaderInterface.hpp
 * @brief Declares a wrapper for shaders
 * @author D3PSI
 */
#ifndef PBR_SHADER_INTERFACE_HPP
#define PBR_SHADER_INTERFACE_HPP

#include "../util/PBR_UTIL.hpp"


namespace pbr {

    namespace core {

        class PBRShaderInterface
        {
        public:

            /**
             * Constructor with arguments
             * @param _shaderSet The shader subdirectory where the shader set 
             * consisting of various different shader types can be found in SHADER_BASE_DIR.
             * The directory must contain filenames according to the following scheme of file endings:
             *      {_shaderSet}/*.vert for a vertex shader
             *      {_shaderSet}/*.frag for a fragment shader
             *      {_shaderSet}/*.geom for a geometry shader
             *      {_shaderSet}/*.comp for a compute shader
             *      {_shaderSet}/*.tes for a tesselation evaluation shader
             *      {_shaderSet}/*.tcs for a tesselation control shader
             * The function will automatically load and compile the shaders it finds
             */
            PBRShaderInterface(const char* _shaderSet);

            /**
             * Default destructor
             */
            ~PBRShaderInterface(void);

        private:

            static const char* SHADER_BASE_DIR;

        };

    }

}

#endif      // PBR_SHADER_INTERFACE_HPP