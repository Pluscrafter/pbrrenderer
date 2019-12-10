/**
 *  @file PBR_CORE.hpp
 *  @brief Contains the declarations of core functions of the PBR engine
 *  @author D3PSI
 */
#ifndef PBR_CORE_HPP
#define PBR_CORE_HPP

#include "../util/PBR_STATUS.hpp"


namespace pbr {

    /**
     *  Contains core functionality for the PBR engine
     */
    namespace core {

        /**
         *  Initializes the windowing library
         *  @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS initGLFW(void);

        /**
         *  Initializes the window
         *  @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS initWindow(void);

        /**
         *  Initializes everything OpenGL-related
         *  @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS initOpenGL(void);

        /**
         *  Contains the main loop
         *  @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS loop(void);

        /**
         *  Cleans all allocated resources and handles shutdown operations
         *  @return Returns 0 or bigger on success, returns a negative number on failure
         */
        PBR_STATUS clean(void);

    }

}

#endif      // PBR_CORE_HPP