#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <conio.h>
#include "Point2d.h"

class Draw2d
{
public:
	static void drawLine(Point2d a, Point2d b, GLFWwindow& window);
	static void drawCircle(Point2d o, int radius, GLFWwindow& window);
	static void drawEllipse(Point2d o, int a, int b, GLFWwindow& window);
};

