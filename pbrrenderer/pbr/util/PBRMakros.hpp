/**
 * @file PBRMakros.hpp
 * @brief Defines useful makros and constant expressions
 * @author D3PSI
 */
#define ASSERT(_val) if(_val < 0) throw std::runtime_error();

#define ORIGIN glm::vec3(0.0f)
#define X_AXIS glm::vec3(1.0f, 0.0f, 0.0f)
#define Y_AXIS glm::vec3(0.0f, 1.0f, 0.0f)
#define Z_AXIS glm::vec3(0.0f, 0.0f, 1.0f)