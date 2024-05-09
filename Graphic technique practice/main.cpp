#include <GLFW/glfw3.h>
#include <iostream>
#include <conio.h>
#include "Point2d.h"
#include "Draw2d.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

void drawLine(GLFWwindow& window) {
    float x, y;
    std::cout << "Nhap vao toa do diem thu 1: ";
    std::cin >> x >> y;
    Point2d a(x, y);
    std::cout << "Nhap vao toa do diem thu 2: ";
    std::cin >> x >> y;
    Point2d b(x, y);
    Draw2d::drawLine(a, b, window);
}

void drawCircle(GLFWwindow& window) {
    float x, y;
    std::cout << "Nhap vao toa do tam: ";
    std::cin >> x >> y;
    Point2d o(x, y);
    std::cout << "Nhap vao ban kinh: ";
    float r; std::cin >> r;
    Draw2d::drawCircle(o,  r, window);
}

void drawEllipse(GLFWwindow& window) {
    float x, y;
    std::cout << "Nhap vao toa do tam: ";
    std::cin >> x >> y;
    Point2d o(x, y);
    std::cout << "Nhap vao ban kinh truc lon: ";
    float a; std::cin >> a;
    std::cout << "Nhap vao ban kinh truc nho: ";
    float b; std::cin >> b;
    Draw2d::drawEllipse(o, a, b, window);
}

void trimSegment(GLFWwindow& window) {
    float x, y;
    std::cout << "Nhap vao toa do trai duoi: ";
    std::cin >> x >> y;
    Point2d llpoint(x, y);
    std::cout << "Nhap vao toa do phai tren: ";
    std::cin >> x >> y;
    Point2d rupoint(x, y);

    std::cout << "Nhap vao toa do diem thu 1: ";
    std::cin >> x >> y;
    Point2d a(x, y);
    std::cout << "Nhap vao toa do diem thu 2: ";
    std::cin >> x >> y;
    Point2d b(x, y);
    Draw2d::trimSegment(llpoint, rupoint, a, b, window);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

int main() {

    // Khởi tạo GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Cấu hình GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Tạo cửa sổ GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Đăng ký callback khi cửa sổ thay đổi kích thước
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Vòng lặp render
    while (!glfwWindowShouldClose(window)) {
        // Xóa màn hình
        glClear(GL_COLOR_BUFFER_BIT);

        // Render ở đây

        // Swap buffers và xử lý sự kiện
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //if (!glfwInit()) {
    //    std::cerr << "Failed to initialize GLFW" << std::endl;
    //    return -1;
    //}

    //GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Bresenham Line Algorithm", nullptr, nullptr);
    //if (!window) {
    //    std::cerr << "Failed to create GLFW window" << std::endl;
    //    glfwTerminate();
    //    return -1;
    //}

    //glfwMakeContextCurrent(window);

    //// Thiết lập tọa độ thực
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //glOrtho(-(WINDOW_WIDTH / 2), (WINDOW_WIDTH / 2), -(WINDOW_HEIGHT / 2), (WINDOW_HEIGHT / 2), -1, 1);
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //bool flag = true;

    //while (flag) {
    //    std::cout << "============================================================\n";
    //    std::cout << "        1. Ve duong thang\n";
    //    std::cout << "        2. Ve duong tron\n";
    //    std::cout << "        3. Ve duong ellipse\n";
    //    std::cout << "        4. Xen tia doan thang\n";
    //    std::cout << "        0. Thoat\n";
    //    std::cout << "============================================================\n";
    //    std::cout << "Chon: ";

    //    int sl;
    //    std::cin >> sl;
    //    switch (sl)
    //    {
    //    case 1:
    //        drawLine(*window);
    //        break;
    //    case 2:
    //        drawCircle(*window);
    //        break;
    //    case 3:
    //        drawEllipse(*window);
    //        break;
    //    case 4:
    //        trimSegment(*window);
    //        break;
    //    case 0:
    //        flag = false;
    //        break;
    //    }
    //}

    glfwTerminate();
    return 0;
}