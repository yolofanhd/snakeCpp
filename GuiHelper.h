//
// Created by dominik on 25.03.22.
//

#ifndef SNAKE_GUIHELPER_H
#define SNAKE_GUIHELPER_H


#include "Snake.h"

class GuiHelper {
private:
    Snake snake = Snake(0,0,0,0);
    pair<int, int> apple;
    void init();
    void drawSnake();
    void close();
public:
    static char input;
    GuiHelper();

    static void getInput();

    bool handleCollision();

    void spawnApple();
};


#endif //SNAKE_GUIHELPER_H
