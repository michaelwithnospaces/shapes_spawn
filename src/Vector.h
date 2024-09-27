// Vector.h

#ifndef VECTOR_H
#define VECTOR_H

#include "raylib.h"

template <typename T>
class Vector2D 
{
public:
    Vector2D() : x(0), y(0) {};
    Vector2D(T _x, T _y) : x(_x), y(_y) {};
    Vector2D(const Vector2D<T>& vec) : x(vec.x), y(vec.y) {};
    Vector2D(const Vector2& vec) : x(vec.x), y(vec.y) {};

    T x;
    T y;

    Vector2D<T> add(Vector2D<T> vec) 
    {
        Vector2D<T> n;
        n.x = this->x + vec.x;
        n.y = this->y + vec.y;
        return n;
    }
};

typedef Vector2D<float> Vector2f;

#endif