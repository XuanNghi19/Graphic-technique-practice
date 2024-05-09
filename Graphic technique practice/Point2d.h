#pragma once
class Point2d {
public:
	Point2d(float x, float y) : x(x), y(y) {}
	Point2d() {}
	float getX() {
		return x;
	}
	float getY() {
		return y;
	}
	void setX(float x) {
		this->x = x;
	}
	void setY(float y) {
		this->y = y;
	}
	void translate(float tx, float ty) {
		x += tx;
		y += ty;
	}
	void scaled(float sx, float sy) {
		x *= sx;
		y *= sy;
	}
	// Hàm xoay điểm xung quanh một điểm cố định
	void rotate(float angle, Point2d center) {
		float radians = angle * (3.14159265359 / 180.0f);
		float cosAngle = cos(radians);
		float sinAngle = sin(radians);

		// Dịch về gốc tọa độ
		x -= center.x;
		y -= center.y;

		// Xoay
		float newX = x * cosAngle - y * sinAngle;
		float newY = x * sinAngle + y * cosAngle;

		// Dịch trở lại vị trí ban đầu
		x = newX + center.x;
		y = newY + center.y;
	}

	void dxX() {
		x = -x;
	}
	void dxY() {
		y = -y;
	}
private:
	float x;
	float y;
};