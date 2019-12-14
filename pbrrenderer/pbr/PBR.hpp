/**
 * Welcome to PBR by D3PSI
 * 
 * This project is open-source and licensed under the GNU General Public License v3.0
 * Please refer to LICENSE.md for further information
 * 
 * Refer to README.md for installation and compilation instructions
 * @file PBR.hpp
 * @brief Main include file for PBR
 * @author D3PSI
 */
#ifndef PBR_HPP
#define PBR_HPP

#include "core/PBR_CORE.hpp"
#include "util/PBR_STATUS.hpp"
#include "ui/SDLLoadingScreen.hpp"
#include "core/util/GLFW_DISPLAY_MODE.hpp"


/**
 * Defines a namespace to minimize variable naming conflicts
 */
namespace pbr {

    extern uint32_t WIDTH;
    extern uint32_t HEIGHT;
    extern const char* TITLE;

    extern const char* LOADING_SCREEN_IMAGE;
    extern const char* APPLICATION_ICON;
    extern GLFW_DISPLAY_MODE DISPLAY_MODE;

    /**
     * Initializes the PBR core engine
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS init(void);

    /**
     * Cleans allocated resources
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS clean(void);

}

#endif      // PBR_HPP