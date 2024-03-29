﻿#include <GLFW/glfw3.h>
#include <iostream>
#include <conio.h>
#include "Point2d.h"
#include "Draw2d.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void bresenhamLine(GLFWwindow& window) {
    int x, y;
    std::cout << "Nhap vao toa do diem thu 1: ";
    std::cin >> x >> y;
    Point2d a(x, y);
    std::cout << "Nhap vao toa do diem thu 2: ";
    std::cin >> x >> y;
    Point2d b(x, y);
    Draw2d::bresenhamLine(a, b, window);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bresenham Line Algorithm", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Thiết lập tọa độ thực
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(WINDOW_WIDTH / 2), (WINDOW_WIDTH / 2), -(WINDOW_HEIGHT / 2), (WINDOW_HEIGHT / 2), -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    bool flag = true;
    while (flag) {
        std::cout << "============================================================\n";
        std::cout << "        1. Ve duong thang voi giai thuat Bresenham\n";
        std::cout << "        0. Thoat\n";
        std::cout << "============================================================\n";
        std::cout << "Chon: ";

        int sl;
        std::cin >> sl;
        switch (sl)
        {
        case 1:
            bresenhamLine(*window);
            break;
        case 0:
            flag = false;
            break;
        }
    }

    glfwTerminate();
    return 0;
}