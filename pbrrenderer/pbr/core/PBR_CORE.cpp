/**
 * @file PBR_CORE.cpp
 * @brief Defines the core components of the PBR engine
 * @author D3PSI
 */
#ifndef PBR_CORE_CPP
#define PBR_CORE_CPP

#include "PBR_CORE.hpp"
#include "../util/flags/PBR_UTIL_FLAGS.hpp"
#include "PBRCameraBase.hpp"


namespace pbr {

    namespace core {

        uint32_t width = pbr::WIDTH;
        uint32_t height = pbr::HEIGHT;

        pbr::core::PBRCameraBase* camera = nullptr;

        float vertices[] = {
            -0.5f, -0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            0.0f,  0.5f, 0.0f
        };

        unsigned int VBO;
        unsigned int VAO;
        unsigned int vs;
        unsigned int fs;
        unsigned int shaderID;

        const char* vShaderSource;
        const char* fShaderSource;

        pbr::util::flags::PBR_STATUS init() {
            pbr::ui::initLoadingScreen();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS execute() {
            pbr::ui::initGLFW();
            pbr::ui::initGLFWWindow();
            pbr::core::initOpenGL();
            pbr::core::loop();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS initOpenGL() {
            if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
                throw std::runtime_error("Failed to gather function pointers for OpenGL through GLAD");
            glViewport(0, 0, pbr::WIDTH, pbr::HEIGHT);
            pbr::ui::loadingScreen->quit();
            glfwShowWindow(pbr::ui::window);
            glfwMakeContextCurrent(pbr::ui::window);
            glfwFocusWindow(pbr::ui::window);
            delete pbr::ui::loadingScreen;
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS loop() {
            pbr::core::setup();
            while(!glfwWindowShouldClose(pbr::ui::window)) {
                keyInput();
                render();
                glfwSwapBuffers(pbr::ui::window);
                glfwPollEvents();
            }
            glfwTerminate();
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS clean() {
            return pbr::util::flags::PBR_OK;
        } 

        pbr::util::flags::PBR_STATUS keyInput() {
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
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setup() {
            pbr::core::setupShaders();
            pbr::core::setupBuffers();
            glEnable(GL_DEPTH_TEST);
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS render() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glUseProgram(shaderID);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);

            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setupShaders() {
            std::string vShader = pbr::util::io::read("shaders/main/shader.vert");
            std::string fShader = pbr::util::io::read("shaders/main/shader.frag");
            vShaderSource = vShader.c_str();
            fShaderSource = fShader.c_str();
            vs = glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vs, 1, &vShaderSource, nullptr);
            glCompileShader(vs);
            int succ;
            char infoLog[1024];
            glGetShaderiv(vs, GL_COMPILE_STATUS, &succ);
            if(!succ) {
                glGetShaderInfoLog(vs, 1024, nullptr, infoLog);
                std::cerr << "Error compiling vertex shader:\n" << infoLog << std::endl;
            }
            fs = glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fs, 1, &fShaderSource, nullptr);
            glCompileShader(fs);
            glGetShaderiv(fs, GL_COMPILE_STATUS, &succ);
            if(!succ) {
                glGetShaderInfoLog(fs, 1024, nullptr, infoLog);
                std::cerr << "Error compiling fragment shader:\n" << infoLog << std::endl;
            }
            shaderID = glCreateProgram();
            glAttachShader(shaderID, vs);
            glAttachShader(shaderID, fs);
            glLinkProgram(shaderID);
            glGetProgramiv(shaderID, GL_LINK_STATUS, &succ);
            if(!succ) {
                glGetProgramInfoLog(shaderID, 1024, nullptr, infoLog);
                std::cerr << "Error linking shader program:\n" << infoLog << std::endl;
            }
            glDeleteShader(vs);
            glDeleteShader(fs);
            return pbr::util::flags::PBR_OK;
        }

        pbr::util::flags::PBR_STATUS setupBuffers() {
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);
            glBindVertexArray(VAO);
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
            glVertexAttribPointer(
                0, 
                3, 
                GL_FLOAT, 
                GL_FALSE, 
                3 * sizeof(float), 
                (void*)0);
            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
            glBindVertexArray(0);
            return pbr::util::flags::PBR_OK;
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