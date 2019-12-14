/**
 * @file GLFW_DISPLAY_MODE.hpp
 * @brief Defines an enumeration for different display modes
 * @author D3PSI
 */
#ifndef GLFW_DISPLAY_MODE_HPP
#define GLFW_DISPLAY_MODE_HPP


namespace pbr {
    
    namespace core {

        typedef enum GLFW_DISPLAY_MODE {
            GLFW_FULLSCREEN,
            GLFW_WINDOWED,
            GLFW_BORDERLESS
        } GLFW_DISPLAY_MODE;

    }

}

#endif      // GLFW_DISPLAY_MODE_HPP