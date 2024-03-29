#pragma once
class Point2d {
public:
	Point2d(int x, int y) : x(x), y(y) {}
	Point2d() {}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setX(double x) {
		this->x = x;
	}
	void setY(double y) {
		this->y = y;
	}
private:
	int x;
	int y;
};