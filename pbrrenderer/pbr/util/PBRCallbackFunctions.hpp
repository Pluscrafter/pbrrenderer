/**
 * @file PBRCallbackFunctions.hpp
 * @brief Defines an enumeration for different callback function types
 * @author D3PSI
 */
#ifndef PBR_CALLBACK_FUNCTIONS_HPP
#define PBR_CALLBACK_FUNCTIONS_HPP

#include <GLFW/glfw3.h>


namespace pbr {

    namespace util {

        /**
         * Defines a callback function for keyboard inputs
         * @param _window The pointer to the GLFWwindow
         */
        typedef void (*PBRKeyboardInputCallbackFun)(GLFWwindow* _window);

    }

}

#endif      // PBR_CALLBACK_FUNCTIONS_HPP