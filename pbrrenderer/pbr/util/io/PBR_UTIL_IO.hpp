/**
 * @file PBR_UTIL_IO.hpp
 * @brief Contains declarations of I/O utility
 * @author D3PSI
 */
#ifndef PBR_UTIL_IO_HPP
#define PBR_UTIL_IO_HPP

#include <fstream>


namespace pbr {

    namespace util {

        namespace io {

            /**
             * Reads a file from disk
             * @param _path The path to the file on disk
             * @return Returns a const char* to the read buffer
             */
            const char* read(const char* _path);

        }

    }

}

#endif      // PBR_UTIL_IO_HPP