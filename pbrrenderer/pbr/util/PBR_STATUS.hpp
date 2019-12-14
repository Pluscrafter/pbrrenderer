/**
 * @file PBR_STATUS.hpp
 * @brief Defines a status code enumeration
 * @author D3PSI
 */
#ifndef PBR_STATUS_HPP
#define PBR_STATUS_HPP


namespace pbr {

    namespace util {

        /**
         * Defines a status code enumeration
         */
        typedef enum PBR_STATUS {
            PBR_OK = 0,
            PBR_FATAL = -1
        } PBR_STATUS;

    }

}

#endif      // PBR_STATUS_HPP