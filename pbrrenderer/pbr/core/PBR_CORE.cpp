/**
 * @file PBR_CORE.cpp
 * @brief Defines the core components of the PBR engine
 * @author D3PSI
 */
#ifndef PBR_CORE_CPP
#define PBR_CORE_CPP

#include "PBR_CORE.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace pbr {

    namespace core {

        GLFWwindow* window = nullptr;
        GLFWmonitor* monitor = nullptr;

        PBR_STATUS init() {
            pbr::core::initGLFW();
            pbr::core::initWindow();
            pbr::core::initOpenGL();
            return PBR_OK;
        }

        PBR_STATUS initGLFW() {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
            glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
            glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
            return PBR_OK;
        }

        PBR_STATUS initWindow() {
            monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            if(pbr::DISPLAY_MODE == GLFW_WINDOWED) {
                window = glfwCreateWindow(
                    pbr::WIDTH,
                    pbr::HEIGHT,
                    pbr::TITLE,
                    nullptr,
                    nullptr);
                glfwSetWindowPos(
                    window,
                    mode->width / 2 - pbr::WIDTH / 2,
                    mode->height / 2 - pbr::HEIGHT / 2);
            }
            else if(pbr::DISPLAY_MODE == GLFW_FULLSCREEN) {
                glfwWindowHint(GLFW_RED_BITS, mode->redBits);
                glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
                glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
                glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
                window = glfwCreateWindow(
                    mode->width,
                    mode->height,
                    pbr::TITLE,
                    monitor,
                    nullptr);
            }
            else if(pbr::DISPLAY_MODE == GLFW_BORDERLESS) {
                window = glfwCreateWindow(
                    mode->width,
                    mode->height,
                    pbr::TITLE,
                    monitor,
                    nullptr);
            }
            glfwMakeContextCurrent(window);
            glfwSwapInterval(0);
            GLFWimage windowIcon[1];
            windowIcon[0].pixels = stbi_load(
                pbr::APPLICATION_ICON,
                &windowIcon[0].width,
                &windowIcon[0].height,
                0,
                STBI_rgb_alpha);
            glfwSetWindowIcon(window, 1, windowIcon);
            stbi_image_free(windowIcon[0].pixels);
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwSetFramebufferSizeCallback(window, pbr::core::framebufferResizeCallback);
            glfwSetCursorPosCallback(window, pbr::core::mouseMoveCallback);
            glfwSetScrollCallback(window, pbr::core::mouseScrollCallback);
            return PBR_OK;
        }

        PBR_STATUS initOpenGL() {
            pbr::loadingScreen->close();
            glfwShowWindow(window);
            glfwFocusWindow(window);
            return PBR_OK;
        }

        PBR_STATUS loop() {
            return PBR_OK;
        }

        PBR_STATUS clean() {
            return PBR_OK;
        } 

        void framebufferResizeCallback(GLFWwindow* _window, int _width, int _height) {
        }

        void mouseMoveCallback(GLFWwindow* _window, double _xPos, double _yPos) {
        }
        
        void mouseScrollCallback(GLFWwindow* _window, double _xOff, double _yOff) {
        }

    }

}

#endif      // PBR_CORE_CPP