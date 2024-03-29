#include "Draw2d.h"

void Draw2d::bresenhamLine(Point2d a, Point2d b, GLFWwindow &window) {


    while (!glfwWindowShouldClose(&window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 1.0f);


        int x1 = a.getX();
        int y1 = a.getY();
        int x2 = b.getX();
        int y2 = b.getY();

        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = (x1 < x2) ? 1 : -1;
        int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            glBegin(GL_POINTS);
            glVertex2i(x1, y1);
            glEnd();

            if (x1 == x2 && y1 == y2) {
                break;
            }

            int e2 = 2 * err;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }

        // Kiểm tra xem có ký tự được nhập từ terminal không
        if (_kbhit()) {
            char ch = _getch();
            if (ch != EOF) {
                break; // Thoát khỏi vòng lặp nếu có ký tự được nhập
            }
        }
        glfwSwapBuffers(&window);
        glfwPollEvents();
    }

}