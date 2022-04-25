// Created by dominik on 18.03.22.

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <vector>
using namespace std;

class Snake {
private:

    int x, y, speed, fgColor, bgColor;
    vector<pair<int,int>> body = {{0,0}};

public:
    Snake(int x, int y, int fgColor, int bgColor);

    int getSpeed() const;

    void setSpeed(int speed);

    const vector<pair<int, int>> &getBody() const;

    void setBody(const vector<pair<int, int>> &body);

    int getX() const {
        return x;
    }
    void setX(int x) {
        Snake::x = x;
    }
    int getY() const {
        return y;
    }
    void setY(int y) {
        Snake::y = y;
    }
    int getFgColor() const {
        return fgColor;
    }
    void setFgColor(int fgColor) {
        Snake::fgColor = fgColor;
    }
    int getBgColor() const {
        return bgColor;
    }
    void setBgColor(int bgColor) {
        Snake::bgColor = bgColor;
    }

    void moveBodies();
    void move(int xAmount,int yAmount);
    void move(const vector<int>& direction);
    void grow();
};

#endif //SNAKE_SNAKE_H
