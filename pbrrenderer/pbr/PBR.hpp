/**
 *  @file PBR.hpp
 *  @brief Main header for PBR
 *  @author D3PSI
 */
#ifndef PBR_HPP
#define PBR_HPP

#include "util/PBR_STATUS.hpp"


/**
 *  Defines a namespace to minimize variable naming conflicts
 */
namespace pbr {

    /**
     *  Initializes the PBR core engine
     *  @return Returns 0 or bigger on success, returns a negative number on failure
     */
    PBR_STATUS init(void);

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

#endif      // PBR_HPP