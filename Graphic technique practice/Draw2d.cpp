#include "Draw2d.h"

// Định nghĩa các mã xén tỉa
const int INSIDE = 0; // Trong vùng cắt
const int LEFT = 1;   // Bên trái
const int RIGHT = 2;  // Bên phải
const int BOTTOM = 4; // Phía dưới
const int TOP = 8;    // Phía trên

// Hàm trả về mã xén tỉa của một điểm
int computeCode(Point2d p, Point2d llpoint, Point2d rupoint) {
    int code = INSIDE; // Mặc định là trong vùng cắt

    if (p.getX() < llpoint.getX()) // Nếu nằm bên trái của vùng cắt
        code |= LEFT;
    else if (p.getX() > rupoint.getX()) // Nếu nằm bên phải của vùng cắt
        code |= RIGHT;

    if (p.getY() < llpoint.getY()) // Nếu nằm phía dưới của vùng cắt
        code |= BOTTOM;
    else if (p.getY() > rupoint.getY()) // Nếu nằm phía trên của vùng cắt
        code |= TOP;

    return code;
}


void Draw2d::drawLine(Point2d a, Point2d b, GLFWwindow &window) {

    std::cout << "t. Tinh tien\n";
    std::cout << "s. Ti le\n";
    std::cout << "r. Quay quanh 1 diem co dinh, anpha\n";
    std::cout << "d. Doi xung\n";
    std::cout << "e. Thoat\n";

    while (!glfwWindowShouldClose(&window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 1.0f);


        float x1 = a.getX();
        float y1 = a.getY();
        float x2 = b.getX();
        float y2 = b.getY();

        float x, y, dx, dy, p;
        dx = x2 - x1;
        dy = y2 - y1;

        double k = (double)dy / dx;
        if (k >= 0 && k < 1) {
            y = y1;
            p = 2 * dy - dx;
            for (x = x1; x <= x2; x++) {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                if (p <= 0) {
                    p += 2 * dy;
                }
                else {
                    p += 2 * (dy - dx);
                    y++;
                }
            }
        }
        else if (k > -1 && k < 0) {
            y = y1;
            p = 2 * dy + dx;
            for (x = x1; x <= x2; x++) {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                if (p <= 0) {
                    p += 2 * dy + 2 * dx;
                    y--;
                }
                else {
                    p += 2 * dy;
                }
            }
        }
        else if (k >= 1) {
            x = x1;
            p = dy - 2 * dx;
            for (y = y1; y <= y2; y++) {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                if (p <= 0) {
                    p += 2 * dy - 2 * dx;
                    x++;
                }
                else {
                    p += -2 * dx;
                }
            }
        }
        else if (k <= -1) {
            x = x1;
            p = -dy - 2 * dx;
            for (y = y1; y <= y2; y++) {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                if (p >= 0) {
                    p += -2 * dy - 2 * dx;
                    x--;
                }
                else {
                    p += -2 * dx;
                }
            }
        }
        glEnd();

        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'e') { // Ấn 'e' để thoát
                break;
            }
            else if (ch == 't') { // Ấn 't' để thay đổi tịnh tiến
                float tx, ty;
                std::cout << "Nhap tinh tien x va y: ";
                std::cin >> tx >> ty;

                // Thực hiện tịnh tiến
                a.translate(tx, ty);
                b.translate(tx, ty);
            }
            else if (ch == 's') {
                float sx, sy;
                std::cout << "Nhap bien doi x va y: ";
                std::cin >> sx >> sy;
                a.scaled(sx, sy);
                b.scaled(sx, sy);
            }
            else if (ch == 'r') {
                float x, y;
                Point2d center;
                std::cout << "Nhap toa do tam: ";
                std::cin >> x >> y;
                center.setX(x);
                center.setY(y);
                float angle;
                std::cout << "Nhap vao goc angle: ";
                std::cin >> angle;
                a.rotate(angle, center);
                b.rotate(angle, center);

            }
            else if (ch == 'd') {
                std::cout << "Muon doi xung qua dau:\n";
                std::cout << "  1.Doi xung qua OX\n";
                std::cout << "  2.Doi xung qua OY\n";
                std::cout << "  3.Doi xung qua O\n";
                int sl; std::cin >> sl;
                if (sl == 1) {
                    a.dxY();
                    b.dxY();
                }
                else if (sl == 2) {
                    a.dxX();
                    b.dxX();
                }
                else if (sl == 3) {
                    a.dxY();
                    b.dxY();
                    a.dxX();
                    b.dxX();
                }
            }
        }
        glfwSwapBuffers(&window);
        glfwPollEvents();
    }

}

void Draw2d::drawCircle(Point2d o, int radius, GLFWwindow& window) {

    std::cout << "t. Tinh tien\n";
    std::cout << "s. Ti le\n";
    std::cout << "r. Quay quanh 1 diem co dinh, anpha\n";
    std::cout << "d. Doi xung\n";
    std::cout << "e. Thoat\n";

    while (!glfwWindowShouldClose(&window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 1.0f);

        int x = 0;
        int y = radius;
        int d = 3 - 2 * radius;

        while (x <= y) {
            // Vẽ các điểm tương đương trên 8 octant
            glBegin(GL_POINTS);
            glVertex2i(o.getX() + x, o.getY() + y);
            glVertex2i(o.getX() - x, o.getY() + y);
            glVertex2i(o.getX() + x, o.getY() - y);
            glVertex2i(o.getX() - x, o.getY() - y);
            glVertex2i(o.getX() + y, o.getY() + x);
            glVertex2i(o.getX() - y, o.getY() + x);
            glVertex2i(o.getX() + y, o.getY() - x);
            glVertex2i(o.getX() - y, o.getY() - x);
            glEnd();

            if (d < 0) {
                d += 4 * x + 6;
            }
            else {
                d += 4 * (x - y) + 10;
                y--;
            }
            x++;
        }

        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'e') { // Ấn 'e' để thoát
                break;
            }
            else if (ch == 't') { // Ấn 't' để thay đổi tịnh tiến
                float tx, ty;
                std::cout << "Nhap tinh tien x va y: ";
                std::cin >> tx >> ty;

                // Thực hiện tịnh tiến
                o.translate(tx, ty);
            }
            else if (ch == 's') {
                float sr;
                std::cout << "Nhap bien doi: ";
                std::cin >> sr;
                radius *= sr;
            }
            else if (ch == 'r') {
                float x, y;
                Point2d center;
                std::cout << "Nhap toa do tam: ";
                std::cin >> x >> y;
                center.setX(x);
                center.setY(y);
                float angle;
                std::cout << "Nhap vao goc angle: ";
                std::cin >> angle;
                o.rotate(angle, center);
            }
            else if (ch == 'd') {
                std::cout << "Muon doi xung qua dau:\n";
                std::cout << "  1.Doi xung qua OX\n";
                std::cout << "  2.Doi xung qua OY\n";
                std::cout << "  3.Doi xung qua O\n";
                int sl; std::cin >> sl;
                if (sl == 1) {
                    o.dxY();
                }
                else if (sl == 2) {
                    o.dxX();
                }
                else if (sl == 3) {
                    o.dxY();
                    o.dxX();
                }
            }
        }
        glfwSwapBuffers(&window);
        glfwPollEvents();
    }
    
}

void Draw2d::drawEllipse(Point2d o, int a, int b, GLFWwindow& window)
{
    while (!glfwWindowShouldClose(&window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 1.0f);

        // Tính các giá trị ban đầu cho thuật toán
        int x = 0, y = b;
        int e2 = b * b - a * a * b + (a * a) / 4;

        // Vẽ 4 điểm đối xứng ban đầu
        glBegin(GL_POINTS);
        glVertex2i(o.getX() + x, o.getY() + y);
        glVertex2i(o.getX() - x, o.getY() + y);
        glVertex2i(o.getX() + x, o.getY() - y);
        glVertex2i(o.getX() - x, o.getY() - y);
        glEnd();

        // Đường Ellip chính
        while (b * b * x <= a * a * y)
        {
            x++;
            if (e2 < 0)
                e2 += b * b * (2 * x + 3);
            else
            {
                y--;
                e2 += b * b * (2 * x + 3) + a * a * (-2 * y + 2);
            }

            // Vẽ 4 điểm đối xứng
            glBegin(GL_POINTS);
            glVertex2i(o.getX() + x, o.getY() + y);
            glVertex2i(o.getX() - x, o.getY() + y);
            glVertex2i(o.getX() + x, o.getY() - y);
            glVertex2i(o.getX() - x, o.getY() - y);
            glEnd();
        }

        // Đường Ellip phần còn lại
        while (y >= 0)
        {
            y--;
            if (e2 > 0)
                e2 += a * a * (-2 * y + 3);
            else
            {
                x++;
                e2 += a * a * (-2 * y + 3) + b * b * (2 * x + 2);
            }

            // Vẽ 4 điểm đối xứng
            glBegin(GL_POINTS);
            glVertex2i(o.getX() + x, o.getY() + y);
            glVertex2i(o.getX() - x, o.getY() + y);
            glVertex2i(o.getX() + x, o.getY() - y);
            glVertex2i(o.getX() - x, o.getY() - y);
            glEnd();
        }

        if (_kbhit()) {
            char ch = _getch();
            if (ch != EOF) {
                break;
            }
        }
        glfwSwapBuffers(&window);
        glfwPollEvents();
    }
}

void Draw2d::trimSegment(Point2d llpoint, Point2d rupoint, Point2d a, Point2d b, GLFWwindow& window) {
    
    int codeA = computeCode(a, llpoint, rupoint);
    int codeB = computeCode(b, llpoint, rupoint);
    bool accept = false;

    while (true) {
        if ((codeA == 0) && (codeB == 0)) { // Cả hai điểm đều trong vùng cắt
            accept = true;
            break;
        }
        else if (codeA & codeB) { // Cả hai điểm cùng nằm ngoài một vùng cắt
            break;
        }
        else {
            int codeOut = codeA ? codeA : codeB; // Chọn điểm nằm ngoài vùng cắt
            Point2d P;

            if (codeOut & TOP) {           // Điểm nằm phía trên vùng cắt
                P.setX(a.getX() + (b.getX() - a.getX()) * (rupoint.getY() - a.getY()) / (b.getY() - a.getY()));
                P.setY(rupoint.getY());
            }
            else if (codeOut & BOTTOM) { // Điểm nằm phía dưới vùng cắt
                P.setX(a.getX() + (b.getX() - a.getX()) * (llpoint.getY() - a.getY()) / (b.getY() - a.getY()));
                P.setY(llpoint.getY());
            }
            else if (codeOut & RIGHT) {  // Điểm nằm bên phải vùng cắt
                P.setY(a.getY() + (b.getY() - a.getY()) * (rupoint.getX() - a.getX()) / (b.getX() - a.getX()));
                P.setX(rupoint.getX());
            }
            else if (codeOut & LEFT) {   // Điểm nằm bên trái vùng cắt
                P.setY(a.getY() + (b.getY() - a.getY()) * (llpoint.getX() - a.getX()) / (b.getX() - a.getX()));
                P.setX(llpoint.getX());
            }

            if (codeOut == codeA) { // Cập nhật P1 hoặc P2
                a = P;
                codeA = computeCode(a, llpoint, rupoint);
            }
            else {
                b = P;
                codeB = computeCode(a, llpoint, rupoint);
            }
        }
    }
    
    while (!glfwWindowShouldClose(&window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 1.0f);

        glBegin(GL_LINE_LOOP);
        glVertex2f(llpoint.getX(), llpoint.getY()); // Bottom left
        glVertex2f(rupoint.getX(), llpoint.getY()); // Bottom right
        glVertex2f(rupoint.getX(), rupoint.getY()); // Top right
        glVertex2f(llpoint.getX(), rupoint.getY()); // Top left
        glEnd();

        float x1 = a.getX();
        float y1 = a.getY();
        float x2 = b.getX();
        float y2 = b.getY();

        float x, y, dx, dy, p;
        dx = x2 - x1;
        dy = y2 - y1;

        double k = (double)dy / dx;
        if (k >= 0 && k < 1) {
            y = y1;
            p = 2 * dy - dx;
            for (x = x1; x <= x2; x++) {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                if (p <= 0) {
                    p += 2 * dy;
                }
                else {
                    p += 2 * (dy - dx);
                    y++;
                }
            }
        }
        else if (k > -1 && k < 0) {
            y = y1;
            p = 2 * dy + dx;
            for (x = x1; x <= x2; x++) {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                if (p <= 0) {
                    p += 2 * dy + 2 * dx;
                    y--;
                }
                else {
                    p += 2 * dy;
                }
            }
        }
        else if (k >= 1) {
            x = x1;
            p = dy - 2 * dx;
            for (y = y1; y <= y2; y++) {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                if (p <= 0) {
                    p += 2 * dy - 2 * dx;
                    x++;
                }
                else {
                    p += -2 * dx;
                }
            }
        }
        else if (k <= -1) {
            x = x1;
            p = -dy - 2 * dx;
            for (y = y1; y <= y2; y++) {
                glBegin(GL_POINTS);
                glVertex2i(x, y);
                if (p >= 0) {
                    p += -2 * dy - 2 * dx;
                    x--;
                }
                else {
                    p += -2 * dx;
                }
            }
        }
        glEnd();

        if (_kbhit()) {
            char ch = _getch();
            if (ch != EOF) {
                break;
            }
        }
        glfwSwapBuffers(&window);
        glfwPollEvents();
    }
}