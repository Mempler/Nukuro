/*
Copyright (c) 2019 Robin A. P.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
*/

#include <window/window.h>

#include <iostream>

static void handle_error(int error, const char* description)
{
    if (error == 65537) return; // The GLFW library is not initialized
    std::cerr << "Error Id: " << error << " Error: " << description << std::endl;
}

Window::Window(int width, int height, const std::string& title) {
    glfwSetErrorCallback(handle_error);

    if (!glfwInit())
        return;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    this->_GLFWwindow = std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)>(window, glfwDestroyWindow);
}

Window::~Window() {
    glfwTerminate();
}

void Window::BeginLoop(Game* game, void (*UpdateEvent)(Game*), void (*RenderEvent)(Game*)) {
    while(!glfwWindowShouldClose(this->_GLFWwindow.get()) && !this->_should_close) {
        glClear(GL_COLOR_BUFFER_BIT);
        UpdateEvent(game);
        RenderEvent(game);

        glfwSwapBuffers(this->_GLFWwindow.get());
        glfwPollEvents();
    }
}

void Window::Close() {
    this->_should_close = true;
}

