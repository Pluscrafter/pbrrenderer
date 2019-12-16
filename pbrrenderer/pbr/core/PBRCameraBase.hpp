/**
 * @file PBRCameraBase.hpp
 * @brief Contains declarations of a base camera class
 * @author D3PSI
 */
#ifndef PBR_CAMERA_BASE_HPP
#define PBR_CAMERA_BASE_HPP

#include "../PBR.hpp"


namespace pbr {

    namespace core {

        class PBRCameraBase 
        {
        public:

            /**
             * Default constructor
             */
            PBRCameraBase(void) = default;

            /**
             * Constructor with arguments
             * @param _pos The starting position of the camera object
             * @param _up The initial up-vector of the camera object, usually (0, 1, 0)
             * @param _yaw The initial yaw-value of the camera object
             * @param _pitch The initial pitch-value of the camera object
             * @param _roll The initial roll-value of the camera object
             */
            PBRCameraBase(
                glm::vec3   _pos    = ORIGIN,
                glm::vec3   _up     = Y_AXIS,
                float       _yaw    = pbr::YAW,
                float       _pitch  = pbr::PITCH,
                float       _roll   = pbr::ROLL);

            /**
             * Default destructor
             */
            ~PBRCameraBase(void) = default;

            /**
             * Queries the current yaw-value
             * @return Returns the current yaw-value
             */
            float yaw(void);

            /**
             * Sets the yaw-value of the camera
             * @param _yaw The new yaw-value of the camera object
             * @return Returns the newly set yaw-value
             */
            float yaw(float _yaw);

            /**
             * Queries the current pitch-value
             * @return Returns the current pitch-value
             */
            float pitch(void);

            /**
             * Sets the pitch-value of the camera
             * @param _pitch The new pitch-value of the camera object
             * @return Returns the newly set pitch-value
             */
            float pitch(float _pitch);

            /**
             * Queries the current roll-value
             * @return Returns the current roll-value
             */
            float roll(void);

            /**
             * Sets the roll-value of the camera
             * @param _roll The new roll-value of the camera object
             * @return Returns the newly set roll-value
             */
            float roll(float _roll);

            private:

                float yaw_val;
                float pitch_val;
                float roll_val;

                glm::vec3 pos;
                glm::vec3 front;
                glm::vec3 worldUp;
                glm::vec3 right;
                glm::vec3 up;

                float fov;

        };

        extern pbr::core::PBRCameraBase* camera;

    }

}

#endif      // PBR_CAMERA_BASE_HPP