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

        SDLLoadingScreen* loadingScreen = nullptr;
        GLFWwindow* window = nullptr;
        GLFWmonitor* monitor = nullptr;

        uint32_t width = pbr::WIDTH;
        uint32_t height = pbr::HEIGHT;

        PBR_STATUS init() {
            pbr::core::loadingScreen = new SDLLoadingScreen(LOADING_SCREEN_IMAGE);
            return PBR_OK;
        }

        PBR_STATUS execute() {
            pbr::core::initGLFW();
            pbr::core::initWindow();
            pbr::core::initOpenGL();
            pbr::core::loop();
            return PBR_OK;
        }

        PBR_STATUS initGLFW() {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
            glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
            glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
            return PBR_OK;
        }

        PBR_STATUS initWindow() {
            monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            if(pbr::DISPLAY_MODE == pbr::core::GLFW_WINDOWED) {
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
            else if(pbr::DISPLAY_MODE == pbr::core::GLFW_FULLSCREEN) {
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
            else if(pbr::DISPLAY_MODE == pbr::core::GLFW_BORDERLESS) {
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
            glfwSetFramebufferSizeCallback(window, pbr::core::framebufferResizeCB);
            glfwSetCursorPosCallback(window, pbr::core::mouseMoveCB);
            glfwSetScrollCallback(window, pbr::core::mouseScrollCB);
            return PBR_OK;
        }

        PBR_STATUS initOpenGL() {
            if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
                throw std::runtime_error("Failed to gather function pointers for OpenGL through GLAD");
            }
            glViewport(0, 0, pbr::WIDTH, pbr::HEIGHT);
            pbr::core::loadingScreen->quit();
            glfwShowWindow(window);
            glfwFocusWindow(window);
            delete pbr::core::loadingScreen;
            return PBR_OK;
        }

        PBR_STATUS loop() {
            while(!glfwWindowShouldClose(pbr::core::window)) {
                keyInput();
                glfwSwapBuffers(pbr::core::window);
                glfwPollEvents();
            }
            glfwTerminate();
            return PBR_OK;
        }

        PBR_STATUS clean() {
            return PBR_OK;
        } 

        PBR_STATUS keyInput() {
            if(glfwGetKey(pbr::core::window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(pbr::core::window, GLFW_TRUE);
            if(pbr::keyInputCB != nullptr)
                keyInputCB(pbr::core::window);
            return PBR_OK;
        }

        void framebufferResizeCB(GLFWwindow* _window, int _width, int _height) {
            pbr::core::width = _width;
            pbr::core::height = _height;
            glViewport(0, 0, _width, _height);
        }

        void mouseMoveCB(GLFWwindow* _window, double _xPos, double _yPos) {
        }
        
        void mouseScrollCB(GLFWwindow* _window, double _xOff, double _yOff) {
        }

    }

}

#endif      // PBR_CORE_CPP