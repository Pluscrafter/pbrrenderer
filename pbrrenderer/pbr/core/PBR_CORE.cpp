/**
 * @file PBR_CORE.cpp
 * @brief Defines the core components of the PBR engine
 * @author D3PSI
 */
#ifndef PBR_CORE_CPP
#define PBR_CORE_CPP

#include "PBR_CORE.hpp"
#include "PBRCameraBase.hpp"


namespace pbr {

    namespace core {

        uint32_t width = pbr::WIDTH;
        uint32_t height = pbr::HEIGHT;

        pbr::core::PBRCameraBase* camera = nullptr;

        pbr::util::PBR_STATUS init() {
            pbr::ui::initLoadingScreen();
            return pbr::util::PBR_OK;
        }

        pbr::util::PBR_STATUS execute() {
            pbr::ui::initGLFW();
            pbr::ui::initGLFWWindow();
            pbr::core::initOpenGL();
            pbr::core::loop();
            return pbr::util::PBR_OK;
        }

        pbr::util::PBR_STATUS initOpenGL() {
            if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
                throw std::runtime_error("Failed to gather function pointers for OpenGL through GLAD");
            glViewport(0, 0, pbr::WIDTH, pbr::HEIGHT);
            pbr::ui::loadingScreen->quit();
            glfwShowWindow(pbr::ui::window);
            glfwFocusWindow(pbr::ui::window);
            delete pbr::ui::loadingScreen;
            return pbr::util::PBR_OK;
        }

        pbr::util::PBR_STATUS loop() {
            while(!glfwWindowShouldClose(pbr::ui::window)) {
                keyInput();
                render();
                glfwSwapBuffers(pbr::ui::window);
                glfwPollEvents();
            }
            glfwTerminate();
            return pbr::util::PBR_OK;
        }

        pbr::util::PBR_STATUS clean() {
            return pbr::util::PBR_OK;
        } 

        pbr::util::PBR_STATUS keyInput() {
            if(glfwGetKey(pbr::ui::window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(pbr::ui::window, GLFW_TRUE);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(pbr::ui::window, GLFW_TRUE);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_1) == GLFW_PRESS)
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_2) == GLFW_PRESS)
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_3) == GLFW_PRESS)
                glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
                glfwSetInputMode(pbr::ui::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            if (glfwGetKey(pbr::ui::window, GLFW_KEY_LEFT_CONTROL) == GLFW_RELEASE)
                glfwSetInputMode(pbr::ui::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            if(pbr::keyInputCB != nullptr)
                keyInputCB(pbr::ui::window);
            return pbr::util::PBR_OK;
        }

        pbr::util::PBR_STATUS setup() {
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            return pbr::util::PBR_OK;
        }

        pbr::util::PBR_STATUS render() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            return pbr::util::PBR_OK;
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