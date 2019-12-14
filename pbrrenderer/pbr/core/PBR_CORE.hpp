/**
 * @file PBR_CORE.hpp
 * @brief Contains the declarations of core functions of the PBR engine
 * @author D3PSI
 */
#ifndef PBR_CORE_HPP
#define PBR_CORE_HPP

#include "../PBR.hpp"
#include "../util/PBR_STATUS.hpp"
#include "../ui/SDLLoadingScreen.hpp"
#include "util/GLFW_DISPLAY_MODE.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace pbr {

    /**
     * Contains core functionality for the PBR engine
     */
    namespace core {

        extern SDLLoadingScreen* loadingScreen;
        extern GLFWwindow* window;
        extern GLFWmonitor* monitor;

        /**
         * Initializes the PBR core engine
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS init(void);

        /**
         * Initializes the windowing library
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS initGLFW(void);

        /**
         * Initializes the window
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS initWindow(void);

        /**
         * Initializes everything OpenGL-related
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS initOpenGL(void);

        /**
         * Contains the main loop
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS loop(void);

        /**
         * Cleans all allocated resources and handles shutdown operations
         * @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS clean(void);

        /**
         * Callback function for window resize events through GLFW
         * @param _window Pointer to the GLFWwindow
         * @param _width The new width of the GLFWwindow
         * @param _height The new height of the GLFWwindow
         */
        void framebufferResizeCallback(GLFWwindow* _window, int _width, int _height);

        /**
         * Callback function for mouse movement events through GLFW
         * @param _window Pointer to the GLFWwindow
         * @param _xPos The new x-position of the mouse pointer
         * @param _yPos The new y-position of the mouse pointer
         */
        void mouseMoveCallback(GLFWwindow* _window, double _xPos, double _yPos);

        /**
         * Callback function for mouse scroll events through GLFW
         * @param _window Pointer to the GLFWwindow
         * @param _xOff The amount of scroll in the x-direction (usually 0)
         * @param _yOff The amount of scroll in the y-direction
         */        
        void mouseScrollCallback(GLFWwindow* _window, double _xOff, double yOff_);

    }

}

#endif      // PBR_CORE_HPP