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

#ifndef NUKORO_WINDOW_H
#define NUKORO_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

class Game;

class Window {
public:
    explicit Window(int width, int height, const std::string& title);
    ~Window();

    void BeginLoop(Game* game, void(*UpdateEvent)(Game*), void(*RenderEvent)(Game*));
    void Close();
private:
    //SDL_GLContext _context;
    std::unique_ptr<GLFWwindow, void(*)(GLFWwindow*)> _GLFWwindow { nullptr, nullptr };
    bool _should_close = false;
};

#endif //NUKORO_WINDOW_H
