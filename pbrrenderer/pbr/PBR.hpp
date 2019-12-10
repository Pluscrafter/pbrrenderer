/**
 *  @file PBR.hpp
 *  @brief Main header for PBR
 *  @author D3PSI
 */
#ifndef PBR_HPP
#define PBR_HPP

#include "core/PBR_CORE.hpp"
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

}

#include "PBR.cpp"

#endif      // PBR_HPP