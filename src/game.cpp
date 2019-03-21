#include <utility>

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

#include <game.h>

void Game::gRun(int width, int height, std::string title) {
    this->GameWindow = std::unique_ptr<Window>(new Window(width, height, std::move(title)));

    this->GameWindow->BeginLoop(this, RealUpdate, RealRender);
}

void Game::RealUpdate(Game* game, SDL_Event *event) {
    switch (event->type) {
        case SDL_QUIT:
            game->GameWindow->Close();
            break;
    }

    game->Update();
}

void Game::RealRender(Game* game) {
    game->Render();
}

