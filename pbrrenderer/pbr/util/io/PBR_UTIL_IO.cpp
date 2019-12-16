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

            const char* read(const char* _path) {
                std::ifstream stream;
                stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
                try {

                }
                catch (std::ifstream::failure _e) {
                }
            }

        }

    }

}

#endif      // PBR_UTIL_IO_CPP