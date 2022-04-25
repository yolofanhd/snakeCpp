#include "GuiHelper.h"
#include "Snake.h"
#include <ncurses.h>
#include <thread>
#include <chrono>

using namespace std::this_thread;

char GuiHelper::input = ' ';


GuiHelper::GuiHelper() {
    GuiHelper::init();
    GuiHelper::snake.setSpeed(1);

    thread inputThread(GuiHelper::getInput);

    GuiHelper::apple = {0,0};


    long lastMillis = 0;
    long currentMillis;
    while(true) {
        currentMillis = clock()/1000;
        if ((currentMillis - lastMillis) >= 50) {
            lastMillis = currentMillis;
            char x = GuiHelper::input;
            if(x=='x') break;
            switch(x) {
                case 'w':
                    GuiHelper::snake.move(-1, 0);
                    break;
                case 'a':
                    GuiHelper::snake.move(0, -1);
                    break;
                case 's':
                    GuiHelper::snake.move(1, 0);
                    break;
                case 'd':
                    GuiHelper::snake.move(0, 1);
                    break;
                default:
                    break;
            }
        }
        if(GuiHelper::handleCollision()) break;
        GuiHelper::drawSnake();
    }

    GuiHelper::close();
}



void GuiHelper::drawSnake() {
    Snake s = GuiHelper::snake;
    auto &body = s.getBody();
    mvprintw(s.getX(), s.getY(), "O");
    for (auto &item : body) {
        mvprintw(item.first, item.second, ".");
    }
    auto &lastItem = body[body.size()-1];
    mvprintw(lastItem.first, lastItem.second, " ");

    move(0, 0);
    refresh();

}

void GuiHelper::init() {
    initscr();
    noecho();
    cbreak();
}

void GuiHelper::close() {
    endwin();
}

void GuiHelper::getInput() {
    while(true) {
        GuiHelper::input = getch();
        if (GuiHelper::input == 'x') break;
    }
}

bool GuiHelper::handleCollision() {
    for (int i=0; i<snake.getBody().size(); i++) {
        if (i==0) continue;
        pair<int, int> item = snake.getBody()[i];
        if (GuiHelper::snake.getX()==item.first && GuiHelper::snake.getY()==item.second) {
            return true;
        }
    }
    if (GuiHelper::snake.getX() == GuiHelper::apple.first && GuiHelper::snake.getY() == GuiHelper::apple.second) {
        GuiHelper::snake.grow();
        GuiHelper::spawnApple();
    }
    return false;
}

void GuiHelper::spawnApple() {
    int x,y;
    getmaxyx(stdscr, x, y);
    int x1 = rand() % x;
    int y1 = rand() % y;
    mvprintw(GuiHelper::apple.second, GuiHelper::apple.first, " ");
    GuiHelper::apple = {x1,y1};
    mvprintw(x1, y1, "@");
}