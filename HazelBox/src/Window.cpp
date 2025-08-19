#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Window.h"


Window::Window():
    m_Handle(nullptr),
    m_Color(Color(1.0f, 1.0f, 1.0f, 1.0f))
{}

Window::~Window()
{
    m_Handle = nullptr;
    m_Color = Color(1.0f, 1.0f, 1.0f, 1.0f);
}

bool Window::Init(int width, int height, Color color, eRenderAPI renderAPI)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);


    m_Handle = glfwCreateWindow(width, height, "Welcome to Hazel's Window!", NULL, NULL);
    m_Color = color;
    if (m_Handle == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(m_Handle);

    // glad  glew glut 
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    glViewport(0, 0, width, height);
    return true;
}

void Window::Update()
{
    while (!glfwWindowShouldClose(m_Handle)) {

        glClearColor(m_Color[0], m_Color[1], m_Color[2], m_Color[3]);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(m_Handle);
        glfwPollEvents();
    }

    glfwTerminate();
}

