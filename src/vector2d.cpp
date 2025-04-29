#include "vector2d.h"

Vector2D::Vector2D(int x, int y) {
    this->x = x;
    this->y = y;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
    this->x += other.x;
    this->y += other.y;

    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other) {
    this->x -= other.x;
    this->y -= other.y;

    return *this;
}
