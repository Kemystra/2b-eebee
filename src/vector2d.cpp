#include "vector2d.h"

#include <cmath>

using namespace std;

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

bool operator==(const Vector2D& a, const Vector2D& b) {
    return (a.x == b.x) && (a.y == b.y);
}

int Vector2D::distance(const Vector2D& other) const {
    // In the assignment, it seems to imply taxicab distance function
    // But the initial GenericRobot kinda not follow that ????
    // Imma use normal Pythagorean distance for now

    int diff_squared_x = pow(this->x - other.x, 2);
    int diff_squared_y = pow(this->y - other.y, 2);

    return static_cast<int>(
        sqrt(x + y)
    );
}
