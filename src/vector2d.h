#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <iostream>

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

#endif // !VECTOR_2D_H
