#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <conio.h>
#include "Point2d.h"

class Draw2d
{
public:
	static void bresenhamLine(Point2d a, Point2d b, GLFWwindow& window);
};

