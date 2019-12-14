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

#include <glad/glad.h>
#include "core/PBR_CORE.hpp"
#include "util/PBR_STATUS.hpp"
#include "ui/SDLLoadingScreen.hpp"
#include "core/util/GLFW_DISPLAY_MODE.hpp"
#include "core/util/PBRCallbackFunctions.hpp"


/**
 * Defines a namespace to minimize variable naming conflicts
 */
namespace pbr {

    extern uint32_t WIDTH;
    extern uint32_t HEIGHT;
    extern const char* TITLE;

    extern const char* LOADING_SCREEN_IMAGE;
    extern const char* APPLICATION_ICON;
    extern pbr::core::GLFW_DISPLAY_MODE DISPLAY_MODE;

    extern pbr::core::PBRKeyboardInputCallbackFun keyInputCB;

    /**
     * Initializes the PBR core engine
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS pbrInit(void);

    /**
     * Starts the main application
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS pbrExecute(void);

    /**
     * Cleans allocated resources
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS pbrClean(void);

    /**
     * Sets the width and height of the application window
     * @param _width The desired width
     * @param _height The desired height
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS pbrSize(uint32_t _width, uint32_t _height);

    /**
     * Sets the title of the application window
     * @param _title The desired title
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS pbrTitle(const char* _title);

    /**
     * Sets the image of the main loading screen
     * @param _image The path to the image on disk
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS pbrLoadingScreenImage(const char* _image);

    /**
     * Sets the icon of the application
     * @param _icon The path to the icon on disk
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS pbrApplicationIcon(const char* _icon);

    /**
     * Sets the keyboard input callback function
     * @param _cbfun The callback function
     * @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS pbrKeyboardInputCallback(pbr::core::PBRKeyboardInputCallbackFun _cbfun);

}

#endif      // PBR_HPP