#include <iostream>


#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

class Vector2D {
public:
    int x;
    int y;
    
    Vector2D(int x_val = 0, int y_val = 0);
    
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    
    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
};

#endif // !MATH_VECTOR_H
