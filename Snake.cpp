//
// Created by dominik on 18.03.22.
//

#include "Snake.h"
#include <cmath>
#include <vector>

Snake::Snake(int x, int y, int fgColor, int bgColor) {
    Snake::x = x;
    Snake::y = y;
    Snake::fgColor = fgColor;
    Snake::bgColor = bgColor;
    Snake::speed = 0;
    Snake::body = {};
}

void Snake::moveBodies() {
    for(int i = 0; i<(Snake::body.size()-1); ++i) {
        Snake::body[i + 1] = Snake::body[i];
    }
    Snake::body[0] = pair(Snake::x, Snake::y);
}
void Snake::move(int xAmount, int yAmount) {
    Snake::moveBodies();
    Snake::x += (xAmount * Snake::speed);
    Snake::y += (yAmount * Snake::speed);
}
void Snake::move(const std::vector<int>& direction) {
    Snake::moveBodies();
    Snake::x += direction[0] * Snake::speed;
    Snake::y += direction[1] * Snake::speed;
}
void Snake::grow() {
    if(Snake::body.empty())
        Snake::body.emplace_back(Snake::x, Snake::y);
    else
        Snake::body.push_back(Snake::body[Snake::body.size()]);
}

int Snake::getSpeed() const {
    return speed;
}

void Snake::setSpeed(int speed) {
    Snake::speed = speed;
}

const vector<pair<int, int>> &Snake::getBody() const {
    return body;
}

void Snake::setBody(const vector<pair<int, int>> &body) {
    Snake::body = body;
}
