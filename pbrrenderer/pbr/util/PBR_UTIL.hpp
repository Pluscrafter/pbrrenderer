/**
 * @file PBR_UTIL.hpp
 * @brief Contains declarations of utility components and functions
 * @author D3PSI
 */
#ifndef PBR_UTIL_HPP
#define PBT_UTIL_HPP

#include "../PBR.hpp"
#include "PBR_DISPLAY_MODE.hpp"
#include "PBR_STATUS.hpp"
#include "PBRCallbackFunctions.hpp"
#include "PBRMakros.hpp"


namespace pbr {

    /**
     * Contains utility functionality for the PBR engine
     */
    namespace util {

        /**
         * Defines a wrapper function to load an image using sdb_image.h, 
         * because said file can only be included in *one* .cpp-source file
         * @param _path The path to the image on disk
         * @param _x The width of the image
         * @param _y The height of the image
         * @param _comp Something with channels and stuff - just put 0
         * @param _req_comp The amount of channels :
         *      STBI_default    = 0, // only used for desired_channels
         *      STBI_grey       = 1,
         *      STBI_grey_alpha = 2,
         *      STBI_rgb        = 3,
         *      STBI_rgb_alpha  = 4
         * @return Returns a as a unsigned char* reinterpreted pointer to a stbi_uc struct
         */
        unsigned char* loadSTBI(
            const char* _path, 
            int*        _x, 
            int*        _y, 
            int*        _comp, 
            int         _req_comp);

        /**
         * Defines a wrapper function to free a loaded image using sdb_image.h, 
         * because said file can only be included in *one* .cpp-source file
         * @param _pixels The array of pixels as an unsigned char pointer
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::PBR_STATUS freeSTBI(unsigned char* _pixels);

    }

}

#endif      // PBR_UTIL_HPP