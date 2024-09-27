// Rectangles.h

#ifndef RECTANGLES_H
#define RECTANGLES_H

#include "Shape.h"

class Rectangles : public Shape 
{
public:
    Rectangles(float length, float height);
    Vector2 sizeToRaylibVector2() const;
    void draw() override;
    void checkWallCollision() override;

private:
    Vector2f m_size;

};

#endif