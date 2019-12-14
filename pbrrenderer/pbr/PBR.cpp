/**
 * Welcome to PBR by D3PSI
 * 
 * This project is open-source and licensed under the GNU General Public License v3.0
 * Please refer to LICENSE.md for further information
 * 
 * Refer to README.md for installation and compilation instructions
 * @file PBR.cpp
 * @brief Main source file for PBR
 * @author D3PSI
 */
#ifndef PBR_CPP
#define PBR_CPP

#include "PBR.hpp"


namespace pbr {

    uint32_t WIDTH = 1280;
    uint32_t HEIGHT = 720;
    const char* TITLE = "Physically-Based Rendering Example by D3PSI";

    const char* LOADING_SCREEN_IMAGE = "res/images/lion.png";
    const char* APPLICATION_ICON = "res/images/lion_cropped.png";
    GLFW_DISPLAY_MODE DISPLAY_MODE = GLFW_WINDOWED;

    PBR_STATUS init() {
        pbr::core::init();
        return PBR_OK;
    }

    PBR_STATUS execute() {
        return pbr::core::execute();
    }

    PBR_STATUS clean() {
        pbr::core::clean();
        return PBR_OK;
    }

    PBR_STATUS size(uint32_t _width, uint32_t _height) {
        WIDTH = _width;
        HEIGHT = _height;
        return PBR_OK;
    }

    PBR_STATUS title(const char* _title) {
        TITLE = _title;
        return PBR_OK;
    }

    PBR_STATUS loadingScreenImage(const char* _image) {
        LOADING_SCREEN_IMAGE = _image;
        return PBR_OK;
    }

    PBR_STATUS applicationIcon(const char* _icon) {
        APPLICATION_ICON = _icon;
        return PBR_OK;
    }

}

#endif      // PBR_CPP