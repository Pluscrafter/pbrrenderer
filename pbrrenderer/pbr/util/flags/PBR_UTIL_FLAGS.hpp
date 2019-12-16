/**
 * @file PBR_UTIL_FLAGS.hpp
 * @brief Contains declarations of all sorts of different flags and enumerations
 * @author D3PSI
 */
#ifndef PBR_UTIL_FLAGS_HPP
#define PBR_UTIL_FLAGS_HPP


namespace pbr {

    namespace util {

        namespace flags {

            /**
             * Defines a status code enumeration
             */
            enum PBR_STATUS {
                PBR_OK = 0,
                PBR_FATAL = -1
            };

            /**
             * Defines an exception code enumeration
             */
            enum PBR_EXCEPTION {
                PBR_IO_EXCEPTION
            };

            /**
             * Defines an enumeration for different display modes
             */
            enum PBR_DISPLAY_MODE {
                PBR_FULLSCREEN,
                PBR_WINDOWED,
                PBR_BORDERLESS
            };

        }

    }

}

#endif      // PBR_UTIL_FLAGS_HPP