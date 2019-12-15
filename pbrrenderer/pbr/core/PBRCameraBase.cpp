/**
 * @file PBRCameraBase.cpp
 * @brief Contains definitions of a base camera class
 * @author D3PSI
 */
#ifndef PBR_CAMERA_BASE_CPP
#define PBR_CAMERA_BASE_CPP

#include "PBRCameraBase.hpp"


pbr::core::PBRCameraBase::PBRCameraBase(
    glm::vec3   _pos,
    glm::vec3   _up,
    float       _yaw,
    float       _pitch,
    float       _roll) {
        this->yaw_val = _yaw;
        this->pitch_val = _pitch;
        this->roll_val = _roll;
}

float pbr::core::PBRCameraBase::yaw() {
    return this->yaw_val;
}

float pbr::core::PBRCameraBase::yaw(float _yaw) {
    this->yaw_val = _yaw;
    return this->yaw_val;
}

float pbr::core::PBRCameraBase::pitch() {
    return this->pitch_val;
}

float pbr::core::PBRCameraBase::pitch(float _pitch) {
    this->pitch_val = _pitch;
    return this->pitch_val;
}

float pbr::core::PBRCameraBase::roll() {
    return this->roll_val;
}

float pbr::core::PBRCameraBase::roll(float _roll) {
    this->roll_val = _roll;
    return this->roll_val;
}

#endif      // PBR_CAMERA_BASE_CPP