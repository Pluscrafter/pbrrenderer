/**
 * @file PBR_DISPLAY_MODE.hpp
 * @brief Defines an enumeration for different display modes
 * @author D3PSI
 */
#ifndef PBR_DISPLAY_MODE_HPP
#define PBR_DISPLAY_MODE_HPP


namespace pbr {
    
    namespace util {

        typedef enum PBR_DISPLAY_MODE {
            PBR_FULLSCREEN,
            PBR_WINDOWED,
            PBR_BORDERLESS
        } PBR_DISPLAY_MODE;

    }

}

#endif      // PBR_DISPLAY_MODE_HPP