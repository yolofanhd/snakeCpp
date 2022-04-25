cmake_minimum_required(VERSION 3.21)
project(snake)

set(CMAKE_CXX_STANDARD 23)


add_executable(snake main.cpp Board.cpp Board.h Snake.cpp Snake.h GuiHelper.cpp GuiHelper.h)
target_link_libraries(${PROJECT_NAME} ncurses)