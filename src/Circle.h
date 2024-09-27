// Circle.h

#ifndef CIRCLE_H
#define CIRCH_H

#include "Shape.h"

class Circle : public Shape 
{
public:
    Circle(int rad);
    void draw() override;
    void checkWallCollision() override;

private:
    int m_radius;
};

#endif