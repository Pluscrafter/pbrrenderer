/**
 * @file PBR_UTIL_IO.cpp
 * @brief Contains definitions of I/O utility
 * @author D3PSI
 */
#ifndef PBR_UTIL_IO_CPP
#define PBR_UTIL_IO_CPP

#include "PBR_UTIL_IO.hpp"
#include "../PBR_UTIL.hpp"


namespace pbr {

    namespace util {

        namespace io {

            std::string read(std::string _path) {
                std::ifstream fileStream;
                std::string buf;
                fileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                try {
                    fileStream.open(_path);
                    std::stringstream contentStream;
                    contentStream << fileStream.rdbuf();
                    fileStream.close();
                    buf = contentStream.str().c_str();
                    return buf;
                }
                catch (std::ifstream::failure& _e) {
                    throw std::runtime_error("Failed to read file from " + _path);
                    return nullptr;
                }
            }

        }

    }

}

#endif      // PBR_UTIL_IO_CPP