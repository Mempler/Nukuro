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

#include <GL/glew.h>

Window::Window(int width, int height, std::string title) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height,
            SDL_WINDOW_OPENGL);

    this->_SDLWindow = std::unique_ptr<SDL_Window, void(*)(SDL_Window*)>(window, SDL_DestroyWindow);

    SDL_GL_SetAttribute (SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute (SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    _context = SDL_GL_CreateContext(this->_SDLWindow.get());

    glewInit();
}

void Window::BeginLoop(Game* game, void (*UpdateEvent)(Game*, SDL_Event*), void (*RenderEvent)(Game*)) {
    const int timePerFrame = static_cast<const int>(pow(2, 4));
    unsigned int lastTime = 0, currentTime = 0, delta = 0;
    SDL_Event event;

    while(!this->_should_close) {
        delta = lastTime - currentTime;

        if (delta < timePerFrame) {
            SDL_Delay(timePerFrame - delta);
        }

        while (SDL_PollEvent(&event)) {
            UpdateEvent(game, &event);
        }

        glClear(GL_COLOR_BUFFER_BIT);
        RenderEvent(game);
        SDL_GL_SwapWindow(this->_SDLWindow.get());

        currentTime = lastTime;
        lastTime = SDL_GetTicks();
    }

    SDL_GL_DeleteContext(this->_context);
    SDL_DestroyWindow(this->_SDLWindow.get());
}

void Window::Close() {
    this->_should_close = true;
}
