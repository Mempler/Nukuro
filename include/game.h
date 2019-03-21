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

#ifndef NUKORO_GAME_H
#define NUKORO_GAME_H

#include <string>

#include <window/window.h>

class Game {
public:
    void gRun(int width, int height, std::string title);

    virtual void Run() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
protected:
    std::unique_ptr<Window> GameWindow { nullptr };
private:

    static void RealUpdate(Game* game, SDL_Event* event);
    static void RealRender(Game* game);
};

#define CREATE_GAME(GameClass, width, height, title) GameClass g_Game; \
                    int main() { \
                        g_Game.gRun(width, height, title); \
                        return 0; \
                    }

#endif //NUKORO_GAME_H
