#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include <iostream>

class Vector2D {
public:
    int x;
    int y;

    static const Vector2D ZERO;
    
    Vector2D(int x_val = 0, int y_val = 0);
    
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    
    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);

    // Magnitude of the vector
    int magnitude() const;

    // This function doesn't accept 'self' parameter, so it must not be a member function
    // Putting it as friend function isn't technically needed; operator== doesn't need private members anyway
    // it's simply just to imply that it is related to this class
    friend bool operator==(const Vector2D& a, const Vector2D& b);

    int distance(const Vector2D& other) const;
};

#endif // !VECTOR_2D_H
