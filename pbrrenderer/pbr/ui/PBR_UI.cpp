/**
 * @file PBR_UI.cpp
 * @brief Defines user-interface components and functions
 * @author D3PSI
 */
#ifndef PBR_UI_CPP
#define PBR_UI_CPP

#include "PBR_UI.hpp"


namespace pbr {

    namespace ui {

        pbr::ui::PBRLoadingScreen* loadingScreen = nullptr;
        GLFWwindow* window = nullptr;
        GLFWmonitor* monitor = nullptr;

        pbr::util::PBR_STATUS initLoadingScreen() {
            pbr::ui::loadingScreen = new pbr::ui::PBRLoadingScreen(LOADING_SCREEN_IMAGE);
            return pbr::util::PBR_OK;
        }

        pbr::util::PBR_STATUS initGLFW() {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
            glfwWindowHint(GLFW_FOCUSED, GLFW_TRUE);
            glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
            return pbr::util::PBR_OK;
        }

        pbr::util::PBR_STATUS initGLFWWindow() {
            pbr::ui::monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(pbr::ui::monitor);
            if(pbr::DISPLAY_MODE == pbr::util::PBR_WINDOWED) {
                pbr::ui::window = glfwCreateWindow(
                    pbr::WIDTH,
                    pbr::HEIGHT,
                    pbr::TITLE,
                    nullptr,
                    nullptr);
                glfwSetWindowPos(
                    pbr::ui::window,
                    mode->width / 2 - pbr::WIDTH / 2,
                    mode->height / 2 - pbr::HEIGHT / 2);
            }
            else if(pbr::DISPLAY_MODE == pbr::util::PBR_FULLSCREEN) {
                glfwWindowHint(GLFW_RED_BITS, mode->redBits);
                glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
                glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
                glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
                pbr::ui::window = glfwCreateWindow(
                    mode->width,
                    mode->height,
                    pbr::TITLE,
                    pbr::ui::monitor,
                    nullptr);
            }
            else if(pbr::DISPLAY_MODE == pbr::util::PBR_BORDERLESS) {
                pbr::ui::window = glfwCreateWindow(
                    mode->width,
                    mode->height,
                    pbr::TITLE,
                    pbr::ui::monitor,
                    nullptr);
            }
            glfwMakeContextCurrent(pbr::ui::window);
            glfwSwapInterval(0);
            GLFWimage windowIcon[1];
            windowIcon[0].pixels = pbr::util::loadSTBI(
                pbr::APPLICATION_ICON,
                &windowIcon[0].width,
                &windowIcon[0].height,
                0,
                4);
            glfwSetWindowIcon(pbr::ui::window, 1, windowIcon);
            pbr::util::freeSTBI(windowIcon[0].pixels);
            glfwSetInputMode(pbr::ui::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            glfwSetFramebufferSizeCallback(pbr::ui::window, pbr::core::framebufferResizeCB);
            glfwSetCursorPosCallback(pbr::ui::window, pbr::core::mouseMoveCB);
            glfwSetScrollCallback(pbr::ui::window, pbr::core::mouseScrollCB);
            return pbr::util::PBR_OK;
        }

    }

}

#endif      // PBR_UI_CPP