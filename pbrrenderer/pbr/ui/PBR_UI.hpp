/**
 * @file PBR_UI.hpp
 * @brief Contains declarations of user-interface components and functions
 * @author D3PSI
 */
#ifndef PBR_UI_HPP
#define PBR_UI_HPP

#include "../PBR.hpp"
#include "PBRLoadingScreen.hpp"


namespace pbr {

    /**
     * Contains user-interface functionality for the PBR engine
     */
    namespace ui {

        extern pbr::ui::PBRLoadingScreen* loadingScreen;
        extern GLFWwindow* window;
        extern GLFWmonitor* monitor;

        /**
         * Starts the main loading screen
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::PBR_STATUS initLoadingScreen(void);

        /**
         * Initializes the GLFW windowing library
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::PBR_STATUS initGLFW(void);

        /**
         * Starts the main application window through GLFW
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        pbr::util::PBR_STATUS initGLFWWindow(void);

    }

}

#endif      // PBR_UI_HPP